/*
 * theta > 0 -> counter-clockwise rotation
 * theta < 0 -> clockwise rotation
 */

#pragma once

#include "LMap.hpp"

class LMapRotateX : public LMap {
public:
	LMapRotateX() {}
	LMapRotateX( const float thetaDeg );

private:
#define	DEG2RAD( DEG ) ( M_PI * DEG / 180.0f )
};

class LMapRotateY : public LMap {
public:
	LMapRotateY() {}
	LMapRotateY( const float thetaDeg );

private:
};

class LMapRotateZ : public LMap {
public:
	LMapRotateZ() {}
	LMapRotateZ( const float thetaDeg );

private:
};
