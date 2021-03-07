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

	return 0;
}
