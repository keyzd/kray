#include "LMapRotate.hpp"

LMapRotateX::LMapRotateX( const float thetaDeg ) {
	float sinTheta = sin( DEG2RAD( thetaDeg ) );
	float cosTheta = cos( DEG2RAD( thetaDeg ) );

	m[0] = Vec4( 1, 0, 0, 0 );
	m[1] = Vec4( 0, cosTheta, sinTheta, 0 );
	m[2] = Vec4( 0, -sinTheta, cosTheta, 0 );
	m[3] = Vec4( 0, 0, 0, 1 );

	mInv = m.Transpose();
}

LMapRotateY::LMapRotateY( const float thetaDeg ) {
	float sinTheta = sin( DEG2RAD( thetaDeg ) );
	float cosTheta = cos( DEG2RAD( thetaDeg ) );

	m[0] = Vec4( cosTheta, 0, -sinTheta, 0 );
	m[1] = Vec4( 0, 1, 0, 0 );
	m[2] = Vec4( sinTheta, 0, cosTheta, 0 );
	m[3] = Vec4( 0, 0, 0, 1 );

	mInv = m.Transpose();
}

LMapRotateZ::LMapRotateZ( const float thetaDeg ) {
	float sinTheta = sin( DEG2RAD( thetaDeg ) );
	float cosTheta = cos( DEG2RAD( thetaDeg ) );

	m[0] = Vec4( cosTheta, sinTheta, 0, 0 );
	m[1] = Vec4( -sinTheta, cosTheta, 0, 0 );
	m[2] = Vec4( 0, 0, 1, 0 );
	m[3] = Vec4( 0, 0, 0, 1 );

	mInv = m.Transpose();
}
