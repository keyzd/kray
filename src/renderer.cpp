#include <stdio.h>
#include <math.h>

#include "renderer.h"
#include "common.h"
#include "materials/ShadeRecord.h"

void R_UpdateFrame( const Scene &scene, Framebuffer &fb ) {
	float ar = float( fb.GetWidth() ) / float( fb.GetHeight() );
	float w = fb.GetWidth();
	float h = fb.GetHeight();

	for( uint32_t y = 0; y < h; y++ ) {
		for( uint32_t x = 0; x < w; x++ ) {
			float u = float( x*2. ) / w - 1.;
			float v = float( y*2. ) / h - 1.;
			u *= ar;
			Ray ray( Vec3(0), normalize( Vec3(u, v, 1.) ) );
			Vec3 color = R_Trace( scene, ray, 0, INFINITY );

			uint8_t r = color.r * 255.;
			uint8_t g = color.g * 255.;
			uint8_t b = color.b * 255.;
			fb.SetPixel( PACK_COLOR( r, g, b ), x, y );
		}
	}
}

Vec3 R_Trace( const Scene &scene, const Ray &ray, float tMin, float tMax ) {
	const IObject* closestObject = R_FindClosestObject( scene, ray, tMin, tMax );

	if( closestObject == NULL ) {
		return R_Miss();
	}

	Vec3 hitPoint;
	closestObject->Intersect(ray, hitPoint);

	ShadeRecord sr( scene );
	sr.hitPoint = hitPoint;
	sr.ray = ray;
	sr.normal = closestObject->GetNormatAt( hitPoint );

	return closestObject->GetMaterial()->Shade( sr );
}

const IObject* R_FindClosestObject( const Scene &scene, const Ray &ray, float tMin, float tMax ) {
	long long closestIndex = -1;
	Vec3 hitPoint;
	float closestT = 10000000000.;

	for(uint32_t i = 0; i < scene.CountObjects(); i++) {
		if( scene.GetObjectPtr( i )->Intersect( ray, hitPoint ) ) {
			float t = length( hitPoint );
			if( t < closestT && t > tMin && t < tMax ) {
				closestIndex = i;
				closestT = t;
			}
		}
	}

	if( closestIndex == -1 ) {
		return NULL;
	}

	return scene.GetObjectPtr( closestIndex );
}

Vec3 R_Miss() {
	return Vec3(1);
}
