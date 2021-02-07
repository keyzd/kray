#pragma once

#include "Vec4.h"

class Mat4 {
public:
	Mat4();
	Mat4(
		double col0_0, double col0_1, double col0_2, double col0_3,
		double col1_0, double col1_1, double col1_2, double col1_3,
		double col2_0, double col2_1, double col2_2, double col2_3,
		double col3_0, double col3_1, double col3_2, double col3_3
	);
	Mat4(double diag);
	Mat4(const Vec4& a_col0, const Vec4& a_col1, const Vec4& a_col2, const Vec4& a_col3);

	Vec4& operator[](unsigned int index);
	Vec4 operator[](unsigned int index) const;

	Mat4 operator*(double t) const;
	const Mat4& operator*=(double t);
	const Mat4& operator*=(const Mat4& m);

	Mat4 operator/(double t) const;
	const Mat4& operator/=(double t);

	Vec4 operator*(const Vec4& u) const;
	Mat4 operator*(const Mat4& m) const;

private:
	Vec4 columns[4];
};

//==================================================

inline Mat4 operator*(const double t, const Mat4 &m) {
	return Mat4(m[0].x*t, m[0].y*t, m[0].z*t, m[0].w*t,
				m[1].x*t, m[1].y*t, m[1].z*t, m[1].w*t,
				m[2].x*t, m[2].y*t, m[2].z*t, m[2].w*t,
				m[3].x*t, m[3].y*t, m[3].z*t, m[3].w*t
	);
}

//==================================================

inline Mat4::Mat4() {
	columns[0] = Vec4(0);
	columns[1] = Vec4(0);
	columns[2] = Vec4(0);
	columns[3] = Vec4(0);
}

inline Mat4::Mat4(
		double col0_0, double col0_1, double col0_2, double col0_3,
		double col1_0, double col1_1, double col1_2, double col1_3,
		double col2_0, double col2_1, double col2_2, double col2_3,
		double col3_0, double col3_1, double col3_2, double col3_3
	) {
	columns[0] = Vec4(col0_0, col0_1, col0_2, col0_3);
	columns[1] = Vec4(col1_0, col1_1, col1_2, col1_3);
	columns[2] = Vec4(col1_0, col1_1, col2_2, col2_3);
	columns[3] = Vec4(col1_0, col1_1, col2_2, col3_3);
}

inline Mat4::Mat4(double diag) {
	columns[0] = Vec4(diag, 0, 0, 0);
	columns[1] = Vec4(0, diag, 0, 0);
	columns[2] = Vec4(0, 0, diag, 0);
	columns[3] = Vec4(0, 0, 0, diag);
}

inline Mat4::Mat4(const Vec4& a_col0, const Vec4& a_col1, const Vec4& a_col2, const Vec4& a_col3) {
	columns[0] = a_col0;
	columns[1] = a_col1;
	columns[2] = a_col2;
	columns[3] = a_col3;
}

inline Vec4& Mat4::operator[](unsigned int index) {
	return columns[index];
}

inline Vec4 Mat4::operator[](unsigned int index) const {
	return columns[index];
}

inline Mat4 Mat4::operator*(double t) const {
	return Mat4(columns[0].x*t, columns[0].y*t, columns[0].z*t, columns[0].w*t,
				columns[1].x*t, columns[1].y*t, columns[1].z*t, columns[1].w*t,
				columns[2].x*t, columns[2].y*t, columns[2].z*t, columns[2].w*t,
				columns[3].x*t, columns[3].y*t, columns[3].z*t, columns[3].w*t
	);
}

inline const Mat4& Mat4::operator*=(double t) {
	columns[0] *= t;
	columns[1] *= t;
	columns[2] *= t;
	columns[3] *= t;
	return *this;
}

inline Mat4 Mat4::operator/(double t) const {
	return Mat4(columns[0].x/t, columns[0].y/t, columns[0].z/t, columns[0].w/t,
				columns[1].x/t, columns[1].y/t, columns[1].z/t, columns[1].w/t,
				columns[2].x/t, columns[2].y/t, columns[2].z/t, columns[2].w/t,
				columns[3].x/t, columns[3].y/t, columns[3].z/t, columns[3].w/t
	);
}

inline const Mat4& Mat4::operator/=(double t) {
	columns[0] /= t;
	columns[1] /= t;
	columns[2] /= t;
	columns[3] /= t;
	return *this;
}

inline Vec4 Mat4::operator*(const Vec4& u) const {
	return Vec4(
		columns[0].x*u.x + columns[1].x*u.y + columns[2].x*u.z + columns[3].x*u.w,
		columns[0].y*u.x + columns[1].y*u.y + columns[2].y*u.z + columns[3].y*u.w,
		columns[0].z*u.x + columns[1].z*u.y + columns[2].z*u.z + columns[3].z*u.w,
		columns[0].w*u.x + columns[1].w*u.y + columns[2].w*u.z + columns[3].w*u.w
	);
}

inline Mat4 Mat4::operator*(const Mat4& m) const {
	Vec4 col0(
		columns[0].x*m[0].x + columns[1].x*m[0].y + columns[2].x*m[0].z + columns[3].x*m[0].w,
		columns[0].y*m[0].x + columns[1].y*m[0].y + columns[2].y*m[0].z + columns[3].y*m[0].w,
		columns[0].z*m[0].x + columns[1].z*m[0].y + columns[2].z*m[0].z + columns[3].z*m[0].w,
		columns[0].w*m[0].x + columns[1].w*m[0].y + columns[2].w*m[0].z + columns[3].w*m[0].w
	);
	Vec4 col1(
		columns[0].x*m[1].x + columns[1].x*m[1].y + columns[2].x*m[1].z + columns[3].x*m[1].w,
		columns[0].y*m[1].x + columns[1].y*m[1].y + columns[2].y*m[1].z + columns[3].y*m[1].w,
		columns[0].z*m[1].x + columns[1].z*m[1].y + columns[2].z*m[1].z + columns[3].z*m[1].w,
		columns[0].w*m[1].x + columns[1].w*m[1].y + columns[2].w*m[1].z + columns[3].w*m[1].w
	);
	Vec4 col2(
		columns[0].x*m[2].x + columns[1].x*m[2].y + columns[2].x*m[2].z + columns[3].x*m[2].w,
		columns[0].y*m[2].x + columns[1].y*m[2].y + columns[2].y*m[2].z + columns[3].y*m[2].w,
		columns[0].z*m[2].x + columns[1].z*m[2].y + columns[2].z*m[2].z + columns[3].z*m[2].w,
		columns[0].w*m[2].x + columns[1].w*m[2].y + columns[2].w*m[2].z + columns[3].w*m[2].w
	);
	Vec4 col3(
		columns[0].x*m[3].x + columns[1].x*m[3].y + columns[2].x*m[3].z + columns[3].x*m[3].w,
		columns[0].y*m[3].x + columns[1].y*m[3].y + columns[2].y*m[3].z + columns[3].y*m[3].w,
		columns[0].z*m[3].x + columns[1].z*m[3].y + columns[2].z*m[3].z + columns[3].z*m[3].w,
		columns[0].w*m[3].x + columns[1].w*m[3].y + columns[2].w*m[3].z + columns[3].w*m[3].w
	);
	return Mat4(col0, col1, col2, col3);
}

inline const Mat4& Mat4::operator*=(const Mat4& m) {
	Vec4 col0(
		columns[0].x*m[0].x + columns[1].x*m[0].y + columns[2].x*m[0].z + columns[3].x*m[0].w,
		columns[0].y*m[0].x + columns[1].y*m[0].y + columns[2].y*m[0].z + columns[3].y*m[0].w,
		columns[0].z*m[0].x + columns[1].z*m[0].y + columns[2].z*m[0].z + columns[3].z*m[0].w,
		columns[0].w*m[0].x + columns[1].w*m[0].y + columns[2].w*m[0].z + columns[3].w*m[0].w
	);
	Vec4 col1(
		columns[0].x*m[1].x + columns[1].x*m[1].y + columns[2].x*m[1].z + columns[3].x*m[1].w,
		columns[0].y*m[1].x + columns[1].y*m[1].y + columns[2].y*m[1].z + columns[3].y*m[1].w,
		columns[0].z*m[1].x + columns[1].z*m[1].y + columns[2].z*m[1].z + columns[3].z*m[1].w,
		columns[0].w*m[1].x + columns[1].w*m[1].y + columns[2].w*m[1].z + columns[3].w*m[1].w
	);
	Vec4 col2(
		columns[0].x*m[2].x + columns[1].x*m[2].y + columns[2].x*m[2].z + columns[3].x*m[2].w,
		columns[0].y*m[2].x + columns[1].y*m[2].y + columns[2].y*m[2].z + columns[3].y*m[2].w,
		columns[0].z*m[2].x + columns[1].z*m[2].y + columns[2].z*m[2].z + columns[3].z*m[2].w,
		columns[0].w*m[2].x + columns[1].w*m[2].y + columns[2].w*m[2].z + columns[3].w*m[2].w
	);
	Vec4 col3(
		columns[0].x*m[3].x + columns[1].x*m[3].y + columns[2].x*m[3].z + columns[3].x*m[3].w,
		columns[0].y*m[3].x + columns[1].y*m[3].y + columns[2].y*m[3].z + columns[3].y*m[3].w,
		columns[0].z*m[3].x + columns[1].z*m[3].y + columns[2].z*m[3].z + columns[3].z*m[3].w,
		columns[0].w*m[3].x + columns[1].w*m[3].y + columns[2].w*m[3].z + columns[3].w*m[3].w
	);
	columns[0] = col0;
	columns[1] = col1;
	columns[2] = col2;
	columns[3] = col3;
	return *this;
}

