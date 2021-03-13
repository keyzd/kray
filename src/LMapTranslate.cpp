#include "LMapTranslate.hpp"

LMapTranslate::LMapTranslate( const Vec3 &delta ) {
	m[0] = Vec4( 1, 0, 0, 0 );
	m[1] = Vec4( 0, 1, 0, 0 );
	m[2] = Vec4( 0, 0, 1, 0 );
	m[3] = Vec4( delta.x, delta.y, delta.z, 1 );

	mInv[0] = Vec4( 1, 0, 0, 0 );
	mInv[1] = Vec4( 0, 1, 0, 0 );
	mInv[2] = Vec4( 0, 0, 1, 0 );
	mInv[3] = Vec4( -delta.x, -delta.y, -delta.z, 1 );
}
