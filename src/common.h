#ifndef COMMON_H
#define COMMON_H

#define ARR_LEN( ptr ) ( sizeof( ptr ) / sizeof( ptr[0] ) )

// ARGB8888 PIXEL FORMAT
#define PACK_COLOR(R, G, B) ( (0<<24) | (R<<16) | (G << 8) | B ) 
#define UNPACK_COLOR_R(COLOR) ( COLOR >> 16 & 255 )
#define UNPACK_COLOR_G(COLOR) ( COLOR >> 8 & 255 )
#define UNPACK_COLOR_B(COLOR) ( COLOR  & 255 )

#endif
