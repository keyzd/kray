#pragma once

#define ARR_LEN( ptr ) ( sizeof( ptr ) / sizeof( ptr[0] ) )

// ARGB8888 PIXEL FORMAT
#define PACK_COLOR( R, G, B ) ( ( 0<<24 ) | ( R<<16 ) | ( G << 8 ) | B ) 
#define UNPACK_COLOR_R(COLOR) ( COLOR >> 16 & 255 )
#define UNPACK_COLOR_G(COLOR) ( COLOR >> 8 & 255 )
#define UNPACK_COLOR_B(COLOR) ( COLOR  & 255 )

template <typename T, typename U, typename V>
inline T clamp( T val, U low, V high ) {
	if( val < low ) return low;
	else if(val > high ) return high;
	else return high;
}

inline float lerp( float t, float v0, float v1 ) {
	return ( 1 - t ) * v0 + t * v1;
}
