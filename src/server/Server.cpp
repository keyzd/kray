#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "Server.hpp"

#include "../PpmImage.hpp"
#include "../common.hpp"
#include "../Scene.hpp"
#include "../Framebuffer.hpp"
#include "renderer.hpp"

#include "../objects.hpp"
#include "../materials.hpp"
#include "../lmaps.hpp"
#include "../math.hpp"
#include "../camera.hpp"

static void* ClientRoutine( void* arg ) {
	Scene scene;

	IMaterial* nm = new MaterialNormalMap;

	Sphere *s1 = new Sphere( Vec3( 0.0f, 0.0f, 2.0f ), 0.5f );
	s1->SetMaterial( nm );

	Sphere *s2 = new Sphere( Vec3( 0.5f, 0.2f, 1.5f ), 0.2f );
	s2->SetMaterial( nm );

	scene.SetObject( s1 );
	scene.SetObject( s2 );

	Framebuffer fb( 480, 480 );

	CameraPinhole cam;
	cam.RenderScene( scene, fb );

	PpmImage img( 480, 480, "out.ppm" );
	img.SetBuf( fb.buf, fb.width*fb.height );
}

Server::Server() {
	options.width = 0;
	options.height = 0;
	options.ssaaOn = 0;
	memset( options.port, '\0', 16 );
	strcpy( options.port, "6666" );
}

bool Server::ArgvOptionsParse( int argc, char *argv[] ) {
	for( int i = 1; i < argc; i+=2 ) {
		if( argv[i][0] != '-' ) {
			printf( "%s: wrong command\n", argv[i] );
			exit( 0 );
		} else {
			if( argv[i+1] == NULL ) {
				printf( "Option %s has no value\n", argv[i] );
				return false;
			} else {
				if( !strcmp( "width", argv[i]+1 ) )
					options.width = atoi( argv[i+1] );
				else if( !strcmp( "height", argv[i]+1 ) )
					options.height = atoi( argv[i+1] );
				else if( !strcmp( "ssaaOn", argv[i]+1 ) ) {
					options.ssaaOn = atoi( argv[i+1] );
				}
				else if( !strcmp( "port", argv[i]+1 ) ) {
					memset( options.port, '\0', 16 );
					strcpy( options.port, argv[i+1] );
				}
			}
		}
	}

	return true;
}

bool Server::Start( int argc, char* argv[] ) {
	socketListen = Socket::MakeListenSocket( options.port );
	return ArgvOptionsParse( argc, argv );
}

void Server::Run() {
	List<pthread_t> threadsIDs;
	pthread_t th;

	while( true ) {
		int socketClient = accept( socketListen, NULL, NULL );
		socketsClients.Push( socketClient );
		pthread_create( &th, NULL, ClientRoutine, NULL );
	}

	pthread_join(th, NULL);
}
