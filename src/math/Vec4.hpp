#pragma once

#include <math.h>

#include "Vec2.hpp"
#include "Vec3.hpp"

class Vec4 {
public:
	union {
		struct { float x, y, z, w; };
		struct { float r, g, b, a; };
	};

	Vec4(float a_x, float a_y, float a_z, float a_w);
	Vec4(float a);
	Vec4();

	Vec4(const Vec2& xy, float a_z, float a_w);
	Vec4(float a_x, const Vec2& yz, float a_w);
	Vec4(float a_x, float a_y, const Vec2& zw);
	Vec4(const Vec2& xy, const Vec2& zw);

	Vec4(const Vec3& xyz, float a_w);
	Vec4(float a_x, const Vec3& yzw);

	const Vec4& operator+() const;
	const Vec4 operator-() const;
	Vec4 operator+(const Vec4 &v) const;
	Vec4 operator-(const Vec4 &v) const;
	Vec4 operator+(const float t) const;
	Vec4 operator-(const float t) const;
	const Vec4& operator=(const Vec4 &v);
	const Vec4& operator*=(const float t);
	const Vec4& operator/=(const float t);
	const Vec4& operator+=(const Vec4& v);
	const Vec4& operator-=(const Vec4& v);
	Vec4 operator*(const float t) const;
	Vec4 operator/(const float t) const;
	bool operator==(const Vec4& u) const;

	friend Vec4 operator*(const float t, const Vec4 &u);
	friend Vec4 operator/(const float t, const Vec4 &u);
	friend Vec4 operator+(const float t, const Vec4 &u);
	friend Vec4 operator-(const float t, const Vec4 &u);
	friend float dot(const Vec4& u, const Vec4& v);
	friend float length(const Vec3& u );
	friend Vec4 normalize(const Vec4& u);
	friend Vec4 reflect(const Vec4& I, const Vec4& N);
};

//==================================================
inline Vec4 operator*(const float t, const Vec4 &u) {
	return Vec4(u.x*t, u.y*t, u.z*t, u.w*t);
}

inline Vec4 operator/(const float t, const Vec4 &u) {
	return Vec4(u.x/t, u.y/t, u.z/t, u.w/t);
}

inline Vec4 operator+(const float t, const Vec4 &u) {
	return Vec4(u.x+t, u.y+t, u.z+t, u.w+t);
}

inline Vec4 operator-(const float t, const Vec4 &u) {
	return Vec4(u.x-t, u.y-t, u.z-t, u.w-t);
}

inline float dot(const Vec4& u, const Vec4& v) {
	return u.x*v.x + u.y*v.y + u.z*v.z + u.w*v.w;
}

inline float length(const Vec4& u ) {
	return sqrt(u.x*u.x + u.y*u.y + u.z*u.z + u.w*u.w);
}

inline Vec4 normalize(const Vec4& u) {
	return u / sqrt(u.x*u.x + u.y*u.y + u.z*u.z + u.w*u.w);
}

inline Vec4 reflect(const Vec4& I, const Vec4& N) {
	return I - N * 2.0 * (I.x*N.x + I.y*N.y + I.z*N.z, I.w*N.w);
}

//==================================================

inline Vec4::Vec4(float a_x, float a_y, float a_z, float a_w) {
	x = a_x; y = a_y; z = a_z; w = a_w;
}

inline Vec4::Vec4(float a) {
	x = y = z = w = a;
}

inline Vec4::Vec4() {
	x = y = z = w = 0;
}

inline Vec4::Vec4(const Vec2& xy, float a_z, float a_w) {
	x = xy.x;
	y = xy.y;
	z = a_z;
	w = a_w;
}

inline Vec4::Vec4(float a_x, const Vec2& yz, float a_w) {
	x = a_x;
	y = yz.x;
	z = yz.y;
	w = a_w;
}

inline Vec4::Vec4(float a_x, float a_y, const Vec2& zw) {
	x = a_x;
	y = a_y;
	z = zw.x;
	w = zw.y;
}

inline Vec4::Vec4(const Vec2& xy, const Vec2& zw) {
	x = xy.x;
	y = xy.y;
	z = zw.x;
	w = zw.y;
}

inline Vec4::Vec4(const Vec3& xyz, float a_w) {
	x = xyz.x;
	y = xyz.y;
	z = xyz.z;
	w = a_w;
}

inline Vec4::Vec4(float a_x, const Vec3& yzw) {
	x = a_x;
	y = yzw.x;
	z = yzw.y;
	w = yzw.z;
}

inline const Vec4& Vec4::operator+() const {
	return *this;
}

inline const Vec4 Vec4::operator-() const {
	return Vec4(-x, -y, -z, -w);
}

inline Vec4 Vec4::operator+(const Vec4 &v) const {
	return Vec4(x+v.x, y+v.y, z+v.z, w+v.w);
}

inline Vec4 Vec4::operator-(const Vec4 &v) const {
	return Vec4(x-v.x, y-v.y, z-v.z, w-v.w);
}

inline Vec4 Vec4::operator+(const float t) const {
	return Vec4(x+t, y+t, z+t, w+t);
}

inline Vec4 Vec4::operator-(const float t) const {
	return Vec4(x-t, y-t, z-t, w-t);
}

inline const Vec4& Vec4::operator=(const Vec4 &v) {
	x = v.x; y = v.y; z = v.z; w = v.w;
	return *this;
}

inline const Vec4& Vec4::operator*=(const float t) {
	x *= t; y *= t; z *= t; w *= t;
	return *this;
}

inline const Vec4& Vec4::operator/=(const float t) {
	x /= t; y /= t; z /= t; w /= t;
	return *this;
}

inline const Vec4& Vec4::operator+=(const Vec4& v) {
	x += v.x; y += v.y; z += v.z; w += v.w;
	return *this;
}

inline const Vec4& Vec4::operator-=(const Vec4& v) {
	x -= v.x; y -= v.y; z -= v.z; w -= v.w;
	return *this;
}

inline Vec4 Vec4::operator*(const float t) const {
	return Vec4(this->x*t, this->y*t, this->z*t, this->w*t);
}

inline Vec4 Vec4::operator/(const float t) const {
	return Vec4(this->x/t, this->y/t, this->z/t, this->w/t);
}

inline bool Vec4::operator==( const Vec4& u ) const {
	if( x == u.x && y == u.y && z == u.z && w == u.w) {
		return true;
	}
	return false;
}

