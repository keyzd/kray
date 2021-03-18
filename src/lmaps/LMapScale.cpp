#include "LMapScale.hpp"

LMapScale::LMapScale( float x, float y, float z ) {
	m[0] = Vec4( x, 0, 0, 0);
	m[1] = Vec4( 0, y, 0, 0);
	m[2] = Vec4( 0, 0, z, 0);
	m[3] = Vec4( 0, 0, 0, 1);

	mInv[0] = Vec4( 1/x, 0, 0, 0);
	mInv[1] = Vec4( 0, 1/y, 0, 0);
	mInv[2] = Vec4( 0, 0, 1/z, 0);
	mInv[3] = Vec4( 0, 0, 0, 1);
}
