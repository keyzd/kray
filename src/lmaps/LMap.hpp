/*
 * Linear map aka Linear transformation
 */

#pragma once

#include "../math/Mat4.hpp"

class LMap {
public:
	LMap() {}
	LMap( const Mat4 &a_m, const Mat4 &a_mInv ) : m( a_m ), mInv( a_mInv ) {}

	Vec4 operator*( const Vec3 &u ) const;
	Vec4 operator*( const Vec4 &u ) const;
	LMap Inverse() const;

protected:
	Mat4 m, mInv;
};

inline Vec4 LMap::operator*(const Vec3 &u) const {
	return m * Vec4( u, 1 );
}

inline Vec4 LMap::operator*(const Vec4 &u) const {
	return m * u;
}

inline LMap LMap::Inverse() const {
	return LMap( mInv, m );
}
