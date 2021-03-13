#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Server.hpp"
#include "../PpmImage.hpp"
#include "../common.hpp"
#include "../Scene.hpp"
#include "../Framebuffer.hpp"
#include "renderer.hpp"

#include "../objects/Sphere.hpp"
#include "../objects/CSGObject.hpp"

#include "../materials/MaterialNormalMap.hpp"

#include "../LMapTranslate.hpp"
#include "../LMapScale.hpp"
#include "../LMapRotate.hpp"

#include "../math/Mat2.hpp"

int main( int argc, char *argv[] ) {
	Server app;

	if( !app.ArgvOptionsParse( argc, argv ) ) {
		return 0;
	}

	Scene scene;

	MaterialNormalMap* nm = new MaterialNormalMap;

	Sphere *s1 = new Sphere( Vec3( 0.0f, 0.0f, 2.0f ), 0.5f );
	s1->SetMaterial( nm );

	Sphere *s2 = new Sphere( Vec3( 0.0f, 0.0f, 1.5f ), 0.2f );
	s2->SetMaterial( nm );

//	CSGObject *csgObj1 = new CSGObject();
//	s1->Difference( s2, csgObj1 );

	scene.SetObject( s1 );
	scene.SetObject( s2 );

	Framebuffer fb( 480, 480 );

	R_UpdateFrame( scene, fb );

	PpmImage img( 480, 480, "out.ppm" );
	img.SetBuf( fb.buf, fb.width*fb.height );

	Vec3 u( 1, 1, 1 );
//	printf( "%f %f %f\n", u.x, u.y, u.z );

	LMapTranslate mt( Vec3( 1, 2, 3 ) );
	LMapScale ms( 2, 2, 2 );

	Vec4 v = mt.Inverse() * u;
//	printf( "%f %f %f\n", v.x, v.y, v.z, v.w );

	Vec4 w = ms.Inverse() * u;
	printf( "%f %f %f\n", w.x, w.y, w.z, w.w );

	LMapRotateZ mx( -90.0 );
	Vec4 v1( 0, 1, 0, 0 );
	Vec4 v2 = mx * v1;
	printf( "%f %f %f %f\n", v2.x, v2.y, v2.z, v2.w );

	return 0;
}
