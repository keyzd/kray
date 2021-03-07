#include <stdio.h>
#include <math.h>

#include "renderer.hpp"
#include "../common.hpp"
#include "../materials/ShadeRecord.hpp"

void R_UpdateFrame( const Scene &scene, Framebuffer &fb ) {
	float ar = float( fb.GetWidth() ) / float( fb.GetHeight() );
	float w = fb.GetWidth();
	float h = fb.GetHeight();

	for( uint32_t y = 0; y < h; y++ ) {
		for( uint32_t x = 0; x < w; x++ ) {
			float u = float( x*2.0f ) / w - 1.0f;
			float v = float( y*2.0f ) / h - 1.0f;
			u *= ar;
			Ray ray( Vec3( 0.0f ), normalize( Vec3( u, v, 1.0f ) ) );
			Vec3 color = R_Trace( scene, ray, 0.0f, INFINITY );

			uint8_t r = color.r * 255.0f;
			uint8_t g = color.g * 255.0f;
			uint8_t b = color.b * 255.0f;
			fb.SetPixel( PACK_COLOR( r, g, b ), x, y );
		}
	}
}

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
