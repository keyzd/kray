#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Client.hpp"

int main( int argc, char *argv[] ) {
	Client app;

	if( !app.Start( argc, argv ) ) {
		return 1;
	}

	app.Run();

	return 0;
}
