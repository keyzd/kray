#pragma once

#include "../utils/List.hpp"
#include "../Socket.hpp"

class Server {
public:
	Server();

	bool ArgvOptionsParse( int argc, char *argv[] );

	void Start();

private:
	struct Options {
		int width;
		int height;
		int ssaaOn;
		char port[16];
	}options;

	int socketListen;
	int socketClient;
};

