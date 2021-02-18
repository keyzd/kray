#include "Sphere.h"

/*
bool Sphere::Intersect( const Ray &ray, Vec3 &intersectAt ) const {
	Vec3 oc = ray.GetOrigin() - position;
	float a = dot( ray.GetDirection(), ray.GetDirection() );
	float b = dot( oc, ( ray.GetDirection() ) * 2.0 );
	float c = dot( oc, ( oc ) - radius*radius );
	float discr = b * b - 4 * a * c;

	if(discr < 0.0) {
		return false;
	}

	float t1 = ( -b + sqrt( discr ) ) / ( 2.0 * a );
	float t2 = ( -b - sqrt( discr ) ) / ( 2.0 * a );
	float t;

	if( t1 < t2) {
		t = t1;
	} else {
		t = t2;
	}

	intersectAt = ray.AtPoint( t );

	return true;
}
*/

Vec3 Sphere::GetNormatAt( const Vec3 &intersectAt ) const {
	return normalize( intersectAt - this->GetPosition() );
}

bool Sphere::Intersect( const Ray &ray, Vec3 &intersectAt ) const {
	Vec3 dir = ray.GetDirection() - ray.GetOrigin();

	if( dot( dir, this->GetPosition() ) <= 0.00 ) {
		return false;
	}

	Vec3 dirn = normalize( dir );
	Vec3 op = dirn * ( dot( this->GetPosition(), dirn ) );
	Vec3 cp = op - this->GetPosition();

	if( length(cp) <= this->GetRadius() ) {
		float pn = sqrtf( powf( this->GetRadius(), 2. ) - powf( length(cp), 2. ) );
		intersectAt = op-pn;
		return true;
	} else {
		return false;
	}
}
