#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "KrayApp.h"
#include "PpmImage.h"
#include "common.h"
#include "Scene.h"
#include "Framebuffer.h"
#include "renderer.h"

#include "objects/Sphere.h"

#include "materials/MaterialNormalMap.h"

int main( int argc, char *argv[] ) {
	KrayApp app;

	if( !app.ArgvOptionsParse( argc, argv ) ) {
		return 0;
	}

	Scene scene;

	Sphere *s1 = new Sphere( Vec3( 0.0, 0.0, 2.0 ), 0.7 );
	MaterialNormalMap* nm = new MaterialNormalMap;

	s1->SetMaterial( nm );

	scene.SetObject( s1 );

	Framebuffer fb( 512, 512 );

	R_UpdateFrame( scene, fb );

	PpmImage img( 512, 512, "out.ppm" );
	img.SetBuf( fb.buf, fb.width*fb.height );

	return 0;
}
