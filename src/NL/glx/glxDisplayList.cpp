#include "NL/glx/glxDisplayList.h"

// Magic number for display list validation
#define DISPLAY_LIST_HEADER 0x45820000

struct DisplayList
{
    /* 0x00 */ u32 m_header;      // Magic number for validation
    /* 0x04 */ void* m_displayList; // Pointer to the actual display list
    /* 0x08 */ u32 m_size;       // Size of the display list
};

/**
 * Offset/Address/Size: 0x0 | 0x801C1E5C | size: 0x2A8
 */
void dlMakeDisplayList(const glModelPacket*, bool)
{
}

/**
 * Offset/Address/Size: 0x2A8 | 0x801C2104 | size: 0x30
 */
u32 dlGetSize(unsigned long addr)
{
    DisplayList *dl = (DisplayList*)addr;

    if (dl == NULL) {
        return 0;
    }
    
    if (dl->m_header != DISPLAY_LIST_HEADER) {
        return 0;
    }
    
    return dl->m_size;        
}

/**
 * Offset/Address/Size: 0x2D8 | 0x801C2134 | size: 0x30
 */
void* dlGetDisplayList(unsigned long addr)
{
    DisplayList *dl = (DisplayList*)addr;

    if (dl == NULL) {
        return NULL;
    }
    
    if (dl->m_header == DISPLAY_LIST_HEADER) {
        return dl->m_displayList;    
    }
    
    return NULL;
}

/**
 * Offset/Address/Size: 0x308 | 0x801C2164 | size: 0x38
 */
bool dlIsDisplayList(unsigned long addr)
{
    DisplayList *dl = (DisplayList*)addr;
    
    if (dl == NULL) {
        return false;
    }
    
    if (dl->m_header != DISPLAY_LIST_HEADER) {
        return false;
    }    

    return (dl->m_header == DISPLAY_LIST_HEADER);
}

/**
 * Offset/Address/Size: 0x340 | 0x801C219C | size: 0x28
 */
unsigned long dlGetStruct(unsigned long addr)
{
    DisplayList *dl = (DisplayList*)addr;
    
    if (dl == NULL) {
        return 0;
    }
    
    if (dl->m_header != DISPLAY_LIST_HEADER) {
        return 0;
    }

    return (unsigned long)dl;
}
