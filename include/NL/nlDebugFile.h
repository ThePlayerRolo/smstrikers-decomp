#ifndef _NLDEBUGFILE_H_
#define _NLDEBUGFILE_H_

void nlCloseFileDebug(void*);
void nlFlushFileDebug(void*);
void nlWriteLineDebug(void*, const char*, bool);
void* nlOpenFileDebug(const char*, bool, bool);

#endif // _NLDEBUGFILE_H_
