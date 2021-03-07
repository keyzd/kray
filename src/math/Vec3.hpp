#pragma once

#include <math.h>

#include "Vec2.hpp"

class Vec3 {
public:
	union {
		struct { float x, y, z; };
		struct { float r, g, b; };
	};

	Vec3(float a_x, float a_y, float a_z);
	Vec3(float a);
	Vec3();

	Vec3(const Vec2& xy, float a_z);
	Vec3(float a_x, const Vec2& yz);

	const Vec3& operator+() const;
	const Vec3 operator-() const;
	Vec3 operator+(const Vec3 &v) const;
	Vec3 operator-(const Vec3 &v) const;
	Vec3 operator+(const float t) const;
	Vec3 operator-(const float t) const;
	const Vec3& operator+=(const float t);
	const Vec3& operator-=(const float t);
	const Vec3& operator=(const Vec3 &v);
	const Vec3& operator*=(const float t);
	const Vec3& operator/=(const float t);
	const Vec3& operator+=(const Vec3& v);
	const Vec3& operator-=(const Vec3& v);
	Vec3 operator*(const float t) const;
	Vec3 operator/(const float t) const;
	bool operator==(const Vec3& u) const;

	friend Vec3 operator*(const float t, const Vec3 &u);
	friend Vec3 operator/(const float t, const Vec3 &u);
	friend Vec3 operator+(const float t, const Vec3 &u);
	friend Vec3 operator-(const float t, const Vec3 &u);
	friend float dot(const Vec3& u, const Vec3& v);
	friend float length(const Vec3& u );
	friend Vec3 normalize(const Vec3& u);
	friend Vec3 reflect(const Vec3& I, const Vec3& N);
};

//==================================================
inline Vec3 operator*(const float t, const Vec3 &u) {
	return Vec3(u.x*t, u.y*t, u.z*t);
}

inline Vec3 operator/(const float t, const Vec3 &u) {
	return Vec3(u.x/t, u.y/t, u.z/t);
}

inline Vec3 operator+(const float t, const Vec3 &u) {
	return Vec3(u.x+t, u.y+t, u.z+t);
}

inline Vec3 operator-(const float t, const Vec3 &u) {
	return Vec3(u.x-t, u.y-t, u.z-t);
}

inline float dot(const Vec3& u, const Vec3& v) {
	return u.x*v.x + u.y*v.y + u.z*v.z;
}

inline float length(const Vec3& u ) {
	return sqrt(u.x*u.x + u.y*u.y + u.z*u.z);
}

inline Vec3 normalize(const Vec3& u) {
	return u / sqrt(u.x*u.x + u.y*u.y + u.z*u.z);
}

inline Vec3 reflect(const Vec3& I, const Vec3& N) {
	return I - N * 2.0 * (I.x*N.x + I.y*N.y + I.z*N.z);
}

//==================================================

inline Vec3::Vec3(float a_x, float a_y, float a_z) {
	x = a_x; y = a_y; z = a_z;
}

inline Vec3::Vec3(float a) {
	x = y = z = a;
}

inline Vec3::Vec3() {
	x = y = z = 0;
}

inline Vec3::Vec3(const Vec2& xy, float a_z) {
	x = xy.x;
	y = xy.y;
	z = a_z;
}

inline Vec3::Vec3(float a_x, const Vec2& yz) {
	x = a_x;
	y = yz.x;
	z = yz.y;
}

inline const Vec3& Vec3::operator+() const {
	return *this;
}

inline const Vec3 Vec3::operator-() const {
	return Vec3(-x, -y, -z);
}

inline Vec3 Vec3::operator+(const Vec3 &v) const {
	return Vec3(x+v.x, y+v.y, z+v.z);
}

inline Vec3 Vec3::operator-(const Vec3 &v) const {
	return Vec3(x-v.x, y-v.y, z-v.z);
}

inline Vec3 Vec3::operator+(const float t) const {
	return Vec3(x+t, y+t, z+t);
}

inline Vec3 Vec3::operator-(const float t) const {
	return Vec3(x-t, y-t, z-t);
}

inline const Vec3& Vec3::operator+=(const float t) {
	x += t; y += t; z += t;
	return *this;
}

inline const Vec3& Vec3::operator-=(const float t) {
	x -= t; y -= t; z -= t;
	return *this;
}

inline const Vec3& Vec3::operator=(const Vec3 &v) {
	x = v.x; y = v.y; z = v.z;
	return *this;
}

inline const Vec3& Vec3::operator*=(const float t) {
	x *= t; y *= t; z *= t;
	return *this;
}

inline const Vec3& Vec3::operator/=(const float t) {
	x /= t; y /= t; z /= t;
	return *this;
}

inline const Vec3& Vec3::operator+=(const Vec3& v) {
	x += v.x; y += v.y; z += v.z;
	return *this;
}

inline const Vec3& Vec3::operator-=(const Vec3& v) {
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}

inline Vec3 Vec3::operator*(const float t) const {
	return Vec3(this->x*t, this->y*t, this->z*t);
}

inline Vec3 Vec3::operator/(const float t) const {
	return Vec3(this->x/t, this->y/t, this->z/t);
}

inline bool Vec3::operator==( const Vec3& u ) const {
	if( x == u.x && y == u.y && z == u.z ) {
		return true;
	}
	return false;
}

