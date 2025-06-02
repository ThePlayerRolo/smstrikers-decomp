#include "types.h"

#include "buffer_io.h"
#include "critical_regions.h"

inline void __convert_from_newlines(unsigned char* buf, size_t* n) {}

inline void __convert_to_newlines(unsigned char* buf, size_t* n) {}

void __prep_buffer(FILE* file) {
    file->buffer_ptr = file->buffer;
    file->buffer_length = file->buffer_size;
    file->buffer_length -= file->position & file->buffer_alignment;
    file->buffer_position = file->position;
}

int __load_buffer(FILE * file, size_t * bytes_loaded, int alignment)
{
	int	ioresult;
	
	__prep_buffer(file);
	
	if (alignment == __dont_align_buffer)
		file->buffer_length = file->buffer_size;	
	
	ioresult = (*file->read_fn)(file->handle, file->buffer, (size_t *) &file->buffer_length, file->idle_fn);
	
	if (ioresult == __io_EOF)     /* mm 961031 */
		file->buffer_length = 0;
	
	if (bytes_loaded)
		*bytes_loaded = file->buffer_length;
	
	if (ioresult)
		return(ioresult);
	
	file->position += file->buffer_length;
// #if	(__dest_os == __win32_os  || __dest_os == __wince_os)
//    /* beginning mm 971031 */
// 	/* In Windows, during input, CRLF is converted to \n, i.e. one
// 	   character less, and buffer_len is adjusted correspondingly.
// 	   However, the value of position must be adjusted so that it is
// 	   a disk file position and not a buffer position.  The following
// 	   code does this.*/
// 	if (!file->file_mode.binary_io)
// 	{
// 		ptrdiff_t		n = file->buffer_len;
// 		unsigned char *	p = file->buffer;
		
// 		while (n--)                    /* jz 971105 */
// 			if (*p++ == '\n')
// 				file->position++;
// 	}
	
// #endif                       /* Ending mm 971031 */

	
	if (!file->file_mode.binary_io)
		__convert_to_newlines(file->buffer, (size_t *) &file->buffer_length);
	
	return(__no_io_error);
}

int __flush_buffer(FILE* file, size_t* bytes_flushed) {
    size_t buffer_len;
    int ioresult;

    buffer_len = file->buffer_ptr - file->buffer;

    if (buffer_len) {
        file->buffer_length = buffer_len;

        if (!file->file_mode.binary_io)
            __convert_from_newlines(file->buffer, (size_t*)&file->buffer_length);

        ioresult = (*file->write_fn)(file->handle, file->buffer, (size_t*)&file->buffer_length,
                                     file->idle_fn);

        if (bytes_flushed)
            *bytes_flushed = file->buffer_length;

        if (ioresult)
            return (ioresult);

        file->position += file->buffer_length;
    }

    __prep_buffer(file);

    return 0;
}

int setvbuf(FILE * file, char * buff, int mode, size_t size)
{
    int kind;

    if (mode == _IONBF)
		fflush(file);

    kind = file->file_mode.file_kind;

	if (file->file_state.io_state != __neutral || kind == __closed_file ) /*970318 bkoz*/
		return(-1);

	if (mode != _IONBF && mode != _IOLBF && mode != _IOFBF)
		return(-1);

	if (file->buffer && file->file_state.free_buffer)
    {
		free(file->buffer);
    }
    __begin_critical_region(stdin_access);
	
	file->file_mode.buffer_mode  = mode;
	file->file_state.free_buffer = 0;
	file->buffer            = (unsigned char*)&file->char_buffer;
	file->buffer_ptr        = (unsigned char*)&file->char_buffer;
	file->buffer_size       = 1;
	file->buffer_length     = 0;
	file->buffer_alignment  = 0;
	
	if (mode == _IONBF || size < 1)
	{
		*(file->buffer_ptr) = '\0';           /*mm 970306*/
        __end_critical_region(stdin_access);
		return(0);
	}
	
	if (!buff)
	{
		if (!(buff = (char *) malloc(size)))
        {
            __end_critical_region(stdin_access);
			return(-1);
        }
			
		file->file_state.free_buffer = 1;
	}
	
	file->buffer      = (unsigned char *) buff;
	file->buffer_ptr  = file->buffer;
	file->buffer_size = size;
	file->buffer_alignment = 0;
	
    __end_critical_region(stdin_access);
	
	return(0);
}
