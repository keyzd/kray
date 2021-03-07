#pragma once

class Server {
public:
	Server();

	bool ArgvOptionsParse( int argc, char *argv[] );

private:
	struct Options {
		int width;
		int height;
		int ssaaOn;
	}options;

};

