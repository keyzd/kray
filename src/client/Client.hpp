#pragma once

#include "../Socket.hpp"
#include "../utils/List.hpp"

class Client {
public:
	Client();

	bool Start( int argc, char* argv[] );
	void Run();

private:
	struct Options {
		int width;
		int height;
		int ssaaOn;
		char port[16];
		char address[16];
	}options;

	List<int> socketsServers;

private:
	bool ArgvOptionsParse( int argc, char* argv[] );
};

