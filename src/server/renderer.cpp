#include <stdio.h>
#include <math.h>

#include "renderer.hpp"
#include "../common.hpp"
#include "../materials/ShadeRecord.hpp"

/*
 * Return pixel color for the ray
 */
Vec3 R_Trace( const Scene &scene, const Ray &ray, float tMin, float tMax ) {
	const IObject* closestObject = R_FindClosestObject( scene, ray, tMin, tMax );

	if( closestObject == NULL ) {
		return R_Miss();
	}

	Vec3 hitPoint;
	closestObject->Intersect( ray, hitPoint, NULL );

	ShadeRecord sr( scene );
	sr.hitPoint = hitPoint;
	sr.ray = ray;
	sr.normal = closestObject->GetNormatAt( hitPoint );

	return closestObject->GetMaterial()->Shade( sr );
}

const IObject* R_FindClosestObject( const Scene &scene, const Ray &ray, float tMin, float tMax ) {
	long long closestIndex = CLOSEST_DEFAULT_INDEX;
	Vec3 hitPoint;
	float closestT = INFINITY;

	for( uint32_t i = 0; i < scene.CountObjects(); i++ ) {
		if( scene.GetObjectPtr( i )->Intersect( ray, hitPoint, NULL ) ) {
			float t = length( hitPoint );
			if( t < closestT && t > tMin && t < tMax ) {
				closestIndex = i;
				closestT = t;
			}
		}
	}

	if( closestIndex == CLOSEST_DEFAULT_INDEX ) {
		return NULL;
	}

	return scene.GetObjectPtr( closestIndex );
}

Vec3 R_Miss() {
	return Vec3( 1.0f );
}
