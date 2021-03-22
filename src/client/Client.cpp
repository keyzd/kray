#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Client.hpp"
#include "../common.hpp"

Client::Client() {
	options.width = 0;
	options.height = 0;
	options.ssaaOn = 0;
	memset( options.port, '\0', 16 );
}

bool Client::ArgvOptionsParse( int argc, char* argv[] ) {
	for( int i = 1; i < argc; i += 2 ) {
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
				else if( !strcmp( "address", argv[i]+1 ) ) {
					memset( options.address, '\0', 16 );
					strcpy( options.address, argv[i+1] );
				}
			}
		}
	}

	return true;
}

bool Client::Start( int argc, char* argv[] ) {
	return ArgvOptionsParse( argc, argv );
}

void Client::Run( ) {
	int serverSock = socket( AF_INET, SOCK_STREAM, 0 );
	assert( serverSock != -1 );

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons( atoi( options.port ) );

	if( !inet_aton( options.address, &( addr.sin_addr ) ) ) {
		printf( "CLIENT::Wrong server address\n" );
		exit( 2 );
	}
	
	int connectFlag = connect( serverSock, ( struct sockaddr* )&addr, sizeof( addr ) );
	assert( connectFlag != -1 );
}
