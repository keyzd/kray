#include "Sphere.hpp"

#ifdef INTERSECT_SPHERE_ALGEBRAIC
bool Sphere::Intersect( const Ray &ray, Vec3 &hitPoint, List<float> *hitT ) const {
	if( dot( ray.GetDirection() - ray.GetOrigin(), position ) <= 0.0f ) {
		return false;
	}

	Vec3 oc = ray.GetOrigin() - position;
	float a = dot( ray.GetDirection(), ray.GetDirection() );
	float b = dot( oc, ( ray.GetDirection() ) * 2.0f );
	float c = dot( oc, oc ) - radius * radius;
	float discr = b * b - 4.0f * a * c;

	if( discr < 0.0f ) {
		return false;
	}

	float t1 = ( -b + sqrt( discr ) ) / ( 2.0f * a );
	float t2 = ( -b - sqrt( discr ) ) / ( 2.0f * a );
	float t;

	if( t1 < t2) {
		t = t1;
	} else {
		t = t2;
	}

	hitPoint = ray.AtPoint( t - 0.0001f );

	if( hitT ) {
		if( t1 < t2) {
			hitT->Push( t1 );
			hitT->Push( t2 );
		} else {
			hitT->Push( t2 );
			hitT->Push( t1 );
		}
	}

	return true;
}
#endif

Vec3 Sphere::GetNormatAt( const Vec3 &hitPoint ) const {
	return normalize( hitPoint - position );
}

#ifndef INTERSECT_SPHERE_ALGEBRAIC
// Work wrong ( why??? )
bool Sphere::Intersect( const Ray &ray, Vec3 &hitPoint, List<float> *hitT ) const {
	Vec3 dir = ray.GetDirection() - ray.GetOrigin();

	if( dot( dir, position ) <= 0.00 ) {
		return false;
	}

	Vec3 dirn = normalize( dir );
	Vec3 op = dirn * ( dot( position, dirn ) );
	Vec3 cp = position - op;
	float cpLen = length( cp );

	if( cpLen <= radius ) {
		float pn = sqrtf( radius * radius - cpLen * cpLen );
		hitPoint = op - pn - 0.001;
		return true;
	}

	return false;
}
#endif
