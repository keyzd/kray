#pragma once

#include <math.h>

class Vec2 {
public:
	struct { double x, y; };

	Vec2(double a_x, double a_y);
	Vec2(double a);
	Vec2();

	const Vec2& operator+() const;
	const Vec2 operator-() const;
	Vec2 operator+(const Vec2 &v) const;
	Vec2 operator-(const Vec2 &v) const;
	Vec2 operator+(const double t) const;
	Vec2 operator-(const double t) const;
	const Vec2& operator=(const Vec2 &v);
	const Vec2& operator*=(const double t);
	const Vec2& operator/=(const double t);
	const Vec2& operator+=(const Vec2& v);
	const Vec2& operator-=(const Vec2& v);
	Vec2 operator*(const double t) const;
	Vec2 operator/(const double t) const;
	bool operator==(const Vec2& u) const;

};

//==================================================
inline Vec2 operator*(const double t, const Vec2 &u) {
	return Vec2(u.x*t, u.y*t);
}

inline Vec2 operator/(const double t, const Vec2 &u) {
	return Vec2(u.x/t, u.y/t);
}

inline Vec2 operator+(const double t, const Vec2 &u) {
	return Vec2(u.x+t, u.y+t);
}

inline Vec2 operator-(const double t, const Vec2 &u) {
	return Vec2(u.x-t, u.y-t);
}

inline double dot(const Vec2& u, const Vec2& v) {
	return u.x*v.x + u.y*v.y;
}

inline double length(const Vec2& u ) {
	return sqrt(u.x*u.x + u.y*u.y);
}

inline Vec2 normalize(const Vec2& u) {
	return u / sqrt(u.x*u.x + u.y*u.y);
}

inline Vec2 reflect(const Vec2& I, const Vec2& N) {
	return I - N * 2.0 * (I.x*N.x + I.y*N.y);
}

//==================================================

inline Vec2::Vec2(double a_x, double a_y) {
	x = a_x; y = a_y;
}

inline Vec2::Vec2(double a) {
	x = y = a;
}

inline Vec2::Vec2() {
	x = y = 0;
}

inline const Vec2& Vec2::operator+() const {
	return *this;
}

inline const Vec2 Vec2::operator-() const {
	return Vec2(-x, -y);
}

inline Vec2 Vec2::operator+(const Vec2 &v) const {
	return Vec2(x+v.x, y+v.y);
}

inline Vec2 Vec2::operator-(const Vec2 &v) const {
	return Vec2(x-v.x, y-v.y);
}

inline Vec2 Vec2::operator+(const double t) const {
	return Vec2(x+t, y+t);
}

inline Vec2 Vec2::operator-(const double t) const {
	return Vec2(x-t, y-t);
}

inline const Vec2& Vec2::operator=(const Vec2 &v) {
	x = v.x; y = v.y;
	return *this;
}

inline const Vec2& Vec2::operator*=(const double t) {
	x *= t; y *= t;
	return *this;
}

inline const Vec2& Vec2::operator/=(const double t) {
	x /= t; y /= t;
	return *this;
}

inline const Vec2& Vec2::operator+=(const Vec2& v) {
	x += v.x; y += v.y;
	return *this;
}

inline const Vec2& Vec2::operator-=(const Vec2& v) {
	x -= v.x; y -= v.y;
	return *this;
}

inline Vec2 Vec2::operator*(const double t) const {
	return Vec2(this->x*t, this->y*t);
}

inline Vec2 Vec2::operator/(const double t) const {
	return Vec2(this->x/t, this->y/t);
}

inline bool Vec2::operator==( const Vec2& u ) const {
	if( x == u.x && y == u.y ) {
		return true;
	}
	return false;
}

