#pragma once

#include "IObject.h"

class Sphere : public IObject {
public:
	Sphere();
	Sphere( const Vec3 &a_pos, const float a_rad) : position( a_pos ), radius( a_rad ) {}

	void SetPosition( const Vec3 &a_pos );
	void SetRadius( const float a_rad );

	Vec3 GetPosition() const;
	float GetRadius() const;

	virtual bool Intersect( const Ray &ray, Vec3 &intersectAt ) const;
	virtual Vec3 GetNormatAt( const Vec3 &intersectAt ) const;

private:
	Vec3 position;
	float radius;

	virtual ~Sphere() {}
};

inline void Sphere::SetPosition( const Vec3 &a_pos ) {
	position = a_pos;
}

inline void Sphere::SetRadius( const float a_rad ) {
	radius = a_rad;
}

inline Vec3 Sphere::GetPosition() const {
	return position;
}

inline float Sphere::GetRadius() const {
	return radius;
}

