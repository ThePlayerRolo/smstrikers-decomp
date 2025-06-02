#pragma ANSI_strict off  /*  990729 vss  empty compilation unit illegal in ANSI C */
#pragma ANSI_strict reset

#include "types.h"
#define __WCMAP_SIZE    256

#define __wcontrol_char 0x01
#define __wmotion_char  0x02
#define __wspace_char   0x04
#define __wpunctuation  0x08
#define __wdigit        0x10
#define __whex_digit    0x20
#define __wlower_case   0x40
#define __wupper_case   0x80

#define wctrl	__wcontrol_char
#define wmotn	__wmotion_char
#define wspac	__wspace_char
#define wpunc	__wpunctuation
#define wdigi	__wdigit
#define whexd	__whex_digit
#define wlowc	__wlower_case
#define wuppc	__wupper_case
#define wdhex	(whexd | wdigi)
#define wuhex	(whexd | wuppc)
#define wlhex	(whexd | wlowc)

wchar_t	__wctype_map[__WCMAP_SIZE] = {
	wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wmotn, wmotn, wmotn, wmotn, wmotn, wctrl, wctrl,
	wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl,
	wspac, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
	wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wdhex, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
	wpunc, wuhex, wuhex, wuhex, wuhex, wuhex, wuhex, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc,
	wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wuppc, wpunc, wpunc, wpunc, wpunc, wpunc,
	wpunc, wlhex, wlhex, wlhex, wlhex, wlhex, wlhex, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc,
	wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wlowc, wpunc, wpunc, wpunc, wpunc, wctrl,
	wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
	wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
	wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
	wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc,
	wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wspac, wpunc, wpunc, wpunc, wpunc, wpunc,
	wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wpunc, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl,
	wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl,
	wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl, wctrl,
};

wchar_t __wupper_map[__WCMAP_SIZE] = {
	0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F,
	0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F,
	L' ',  L'!',  L'"',  L'#',  L'$',  L'%',  L'&',  L'\'', L'(',  L')',  L'*',  L'+',  L',',  L'-',  L'.',  L'/',
	L'0',  L'1',  L'2',  L'3',  L'4',  L'5',  L'6',  L'7',  L'8',  L'9',  L':',  L';',  L'<',  L'=',  L'>',  L'?',
	L'@',  L'A',  L'B',  L'C',  L'D',  L'E',  L'F',  L'G',  L'H',  L'I',  L'J',  L'K',  L'L',  L'M',  L'N',  L'O',
	L'P',  L'Q',  L'R',  L'S',  L'T',  L'U',  L'V',  L'W',  L'X',  L'Y',  L'Z',  L'[',  L'\\', L']',  L'^',  L'_',
	L'`',  L'A',  L'B',  L'C',  L'D',  L'E',  L'F',  L'G',  L'H',  L'I',  L'J',  L'K',  L'L',  L'M',  L'N',  L'O',
	L'P',  L'Q',  L'R',  L'S',  L'T',  L'U',  L'V',  L'W',  L'X',  L'Y',  L'Z',  L'{',  L'|',  L'}',  L'~',  0x007F,
	0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087, 0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
	0x0090, 0x0091, 0x0092, 0x0093, 0x0094, 0x0095, 0x0096, 0x0097, 0x0098, 0x0099, 0x009A, 0x009B, 0x009C, 0x009D, 0x009E, 0x009F,
	0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7, 0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
	0x00B0, 0x00B1, 0x00B2, 0x00B3, 0x00B4, 0x00B5, 0x00B6, 0x00B7, 0x00B8, 0x00B9, 0x00BA, 0x00BB, 0x00BC, 0x00BD, 0x00BE, 0x00BF,
	0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7, 0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
	0x00D0, 0x00D1, 0x00D2, 0x00D3, 0x00D4, 0x00D5, 0x00D6, 0x00D7, 0x00D8, 0x00D9, 0x00DA, 0x00DB, 0x00DC, 0x00DD, 0x00DE, 0x00DF,
	0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7, 0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
	0x00F0, 0x00F1, 0x00F2, 0x00F3, 0x00F4, 0x00F5, 0x00F6, 0x00F7, 0x00F8, 0x00F9, 0x00FA, 0x00FB, 0x00FC, 0x00FD, 0x00FE, 0x00FF
};
