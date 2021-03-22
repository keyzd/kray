#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Server.hpp"

int main( int argc, char *argv[] ) {
	Server app;

	if( !app.Start( argc, argv ) ) {
		return 1;
	}

	app.Run();

	return 0;
}
