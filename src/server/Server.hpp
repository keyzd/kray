#pragma once

#include "../utils/List.hpp"
#include "../Socket.hpp"

static void* ClientRoutine( void* arg );

class Server {
public:
	Server();

	bool Start( int argc, char* argv[] );
	void Run();

private:
	struct Options {
		int width;
		int height;
		int ssaaOn;
		char port[16];
	}options;

	int socketListen;
	List<int> socketsClients;

private:
	bool ArgvOptionsParse( int argc, char* argv[] );
};

