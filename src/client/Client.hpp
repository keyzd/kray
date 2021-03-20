#pragma once

#include "../Socket.hpp"

class Client {
public:
	Client();

	bool ArgvOptionsParse( int argc, char *argv[] );

private:
	struct Options {
		int width;
		int height;
		int ssaaOn;
	}options;

	List<int> socketsServers;
};

