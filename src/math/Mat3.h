#pragma once

#include "Vec3.h"

class Mat3 {
public:
	Mat3();
	Mat3(
		float col0_0, float col0_1, float col0_2,
		float col1_0, float col1_1, float col1_2,
		float col2_0, float col2_1, float col2_2
	);
	Mat3(float diag);
	Mat3(const Vec3& a_col0, const Vec3& a_col1, const Vec3& a_col2);

	Vec3& operator[](unsigned int index);
	Vec3 operator[](unsigned int index) const;

	Mat3 operator*(float t) const;
	const Mat3& operator*=(float t);
	const Mat3& operator*=(const Mat3& m);

	Mat3 operator/(float t) const;
	const Mat3& operator/=(float t);

	Vec3 operator*(const Vec3& u) const;
	Mat3 operator*(const Mat3& m) const;

private:
	Vec3 columns[3];
};

//==================================================

inline Mat3 operator*(const float t, const Mat3 &m) {
	return Mat3(m[0].x*t, m[0].y*t, m[0].z*t,
				m[1].x*t, m[1].y*t, m[1].z*t,
				m[2].x*t, m[2].y*t, m[2].z*t
	);
}

//==================================================

inline Mat3::Mat3() {
	columns[0] = Vec3(0);
	columns[1] = Vec3(0);
	columns[2] = Vec3(0);
}

inline Mat3::Mat3(float col0_0, float col0_1, float col0_2,
				  float col1_0, float col1_1, float col1_2,
				  float col2_0, float col2_1, float col2_2) {
	columns[0] = Vec3(col0_0, col0_1, col0_2);
	columns[1] = Vec3(col1_0, col1_1, col1_2);
	columns[2] = Vec3(col1_0, col1_1, col2_2);
}

inline Mat3::Mat3(float diag) {
	columns[0] = Vec3(diag, 0, 0);
	columns[1] = Vec3(0, diag, 0);
	columns[2] = Vec3(0, 0, diag);
}

inline Mat3::Mat3(const Vec3& a_col0, const Vec3& a_col1, const Vec3& a_col2) {
	columns[0] = a_col0;
	columns[1] = a_col1;
	columns[2] = a_col2;
}

inline Vec3& Mat3::operator[](unsigned int index) {
	return columns[index];
}

inline Vec3 Mat3::operator[](unsigned int index) const {
	return columns[index];
}

inline Mat3 Mat3::operator*(float t) const {
	return Mat3(columns[0].x*t, columns[0].y*t, columns[0].z*t,
				columns[1].x*t, columns[1].y*t, columns[1].z*t,
				columns[2].x*t, columns[2].y*t, columns[2].z*t
	);
}

inline const Mat3& Mat3::operator*=(float t) {
	columns[0] *= t;
	columns[1] *= t;
	columns[2] *= t;
	return *this;
}

inline Mat3 Mat3::operator/(float t) const {
	return Mat3(columns[0].x/t, columns[0].y/t, columns[0].z/t,
				columns[1].x/t, columns[1].y/t, columns[1].z/t,
				columns[2].x/t, columns[2].y/t, columns[2].z/t
	);
}

inline const Mat3& Mat3::operator/=(float t) {
	columns[0] /= t;
	columns[1] /= t;
	columns[2] /= t;
	return *this;
}

inline Vec3 Mat3::operator*(const Vec3& u) const {
	return Vec3(
		columns[0].x*u.x+columns[1].x*u.y+columns[2].x*u.z,
		columns[0].y*u.x+columns[1].y*u.y+columns[2].y*u.z,
		columns[0].z*u.x+columns[1].z*u.y+columns[2].z*u.z
	);
}

inline Mat3 Mat3::operator*(const Mat3& m) const {
	Vec3 col0(
		columns[0].x*m[0].x + columns[1].x*m[0].y + columns[2].x*m[0].z,
		columns[0].y*m[0].x + columns[1].y*m[0].y + columns[2].y*m[0].z,
		columns[0].z*m[0].x + columns[1].z*m[0].y + columns[2].z*m[0].z
	);
	Vec3 col1(
		columns[0].x*m[1].x + columns[1].x*m[1].y + columns[2].x*m[1].z,
		columns[0].y*m[1].x + columns[1].y*m[1].y + columns[2].y*m[1].z,
		columns[0].z*m[1].x + columns[1].z*m[1].y + columns[2].z*m[1].z
	);

	Vec3 col2(
		columns[0].x*m[2].x + columns[1].x*m[2].y + columns[2].x*m[2].z,
		columns[0].y*m[2].x + columns[1].y*m[2].y + columns[2].y*m[2].z,
		columns[0].z*m[2].x + columns[1].z*m[2].y + columns[2].z*m[2].z
	);
	return Mat3(col0, col1, col2);
}

inline const Mat3& Mat3::operator*=(const Mat3& m) {
	Vec3 col0(
		columns[0].x*m[0].x + columns[1].x*m[0].y + columns[2].x*m[0].z,
		columns[0].y*m[0].x + columns[1].y*m[0].y + columns[2].y*m[0].z,
		columns[0].z*m[0].x + columns[1].z*m[0].y + columns[2].z*m[0].z
	);
	Vec3 col1(
		columns[0].x*m[1].x + columns[1].x*m[1].y + columns[2].x*m[1].z,
		columns[0].y*m[1].x + columns[1].y*m[1].y + columns[2].y*m[1].z,
		columns[0].z*m[1].x + columns[1].z*m[1].y + columns[2].z*m[1].z
	);

	Vec3 col2(
		columns[0].x*m[2].x + columns[1].x*m[2].y + columns[2].x*m[2].z,
		columns[0].y*m[2].x + columns[1].y*m[2].y + columns[2].y*m[2].z,
		columns[0].z*m[2].x + columns[1].z*m[2].y + columns[2].z*m[2].z
	);
	columns[0] = col0;
	columns[1] = col1;
	columns[2] = col2;
	return *this;
}

