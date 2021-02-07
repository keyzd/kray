#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "KrayApp.h"
#include "PpmImage.h"
#include "common.h"

int main( int argc, char *argv[] ) {
	KrayApp app;

	if( !app.ArgvOptionsParse( argc, argv ) ) {
		return 0;
	}

	return 0;
}
