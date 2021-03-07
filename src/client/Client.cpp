#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Client.hpp"
#include "../common.hpp"

Client::Client() {
	options.width = 0;
	options.height = 0;
	options.ssaaOn = 0;
}

bool Client::ArgvOptionsParse( int argc, char *argv[] ) {
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
			}
		}
	}
	return true;
}
