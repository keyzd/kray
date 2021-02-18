#pragma once

class KrayApp {
public:
	KrayApp();

	bool ArgvOptionsParse( int argc, char *argv[] );

private:
	struct Options {
		int width;
		int height;
		int ssaaOn;
	}options;

};

