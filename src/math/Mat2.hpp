#pragma once

#include "Vec2.hpp"

class Mat2 {
public:
	Mat2();
	Mat2(float col0_0, float col0_1, float col1_0, float col1_1);
	Mat2(float diag);
	Mat2(const Vec2& a_col0, const Vec2& a_col1);

	Mat2 Transpose() const;

	Vec2& operator[](unsigned int index);
	Vec2 operator[](unsigned int index) const;

	Mat2 operator*(float t) const;
	const Mat2& operator*=(float t);
	const Mat2& operator*=(const Mat2& m);

	Mat2 operator/(float t) const;
	const Mat2& operator/=(float t);

	Vec2 operator*(const Vec2& u) const;
	Mat2 operator*(const Mat2& m) const;

private:
	Vec2 columns[2];
};

//==================================================

inline Mat2 operator*(const float t, const Mat2 &m) {
	return Mat2(m[0].x*t, m[0].y*t, m[1].x*t, m[1].y*t);
}

//==================================================

inline Mat2::Mat2() {
	columns[0] = Vec2(0);
	columns[1] = Vec2(0);
}

inline Mat2::Mat2(float col0_0, float col0_1, float col1_0, float col1_1) {
	columns[0] = Vec2(col0_0, col0_1);
	columns[1] = Vec2(col1_0, col1_1);
}

inline Mat2::Mat2(float diag) {
	columns[0] = Vec2(diag, 0);
	columns[1] = Vec2(0, diag);
}

inline Mat2::Mat2(const Vec2& a_col0, const Vec2& a_col1) {
	columns[0] = a_col0;
	columns[1] = a_col1;
}

inline Mat2 Mat2::Transpose() const {
	Vec2 col0( columns[0].x, columns[1].x );
	Vec2 col1( columns[0].y, columns[1].y );
	return Mat2( col0, col1 );
}

inline Vec2& Mat2::operator[](unsigned int index) {
	return columns[index];

}

inline Vec2 Mat2::operator[](unsigned int index) const {
	return columns[index];
}

inline Mat2 Mat2::operator*(float t) const {
	return Mat2(columns[0].x*t, columns[0].y*t, columns[1].x*t, columns[1].y*t);
}

inline const Mat2& Mat2::operator*=(float t) {
	columns[0] *= t;
	columns[1] *= t;
	return *this;
}

inline Mat2 Mat2::operator/(float t) const {
	return Mat2(columns[0].x/t, columns[0].y/t, columns[1].x/t, columns[1].y/t);
}

inline const Mat2& Mat2::operator/=(float t) {
	columns[0] /= t;
	columns[1] /= t;
	return *this;
}

inline Vec2 Mat2::operator*(const Vec2& u) const {
	return Vec2(
		columns[0].x*u.x+columns[1].x*u.y,
		columns[0].y*u.x+columns[1].y*u.y
	);
}

inline Mat2 Mat2::operator*(const Mat2& m) const {
	Vec2 col0(columns[0].x*m[0].x + columns[1].x*m[0].y, columns[0].y*m[0].x + columns[1].y*m[0].y);
	Vec2 col1(columns[0].x*m[1].x + columns[1].x*m[1].y, columns[0].y*m[1].x + columns[1].y*m[1].y);
	return Mat2(col0, col1);
}

const Mat2& Mat2::operator*=(const Mat2& m) {
	Vec2 col0(columns[0].x*m[0].x + columns[1].x*m[0].y, columns[0].y*m[0].x + columns[1].y*m[0].y);
	Vec2 col1(columns[0].x*m[1].x + columns[1].x*m[1].y, columns[0].y*m[1].x + columns[1].y*m[1].y);
	columns[0] = col0;
	columns[1] = col1;
	return *this;
}

