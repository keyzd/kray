#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <time.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Socket {
public:
	static void SendMsg( int sockSendTo, const char* msg );
	static int RecvMsg( int sockRecvFrom, char** msg );
	static int MakeListenSocket( const char* port );
};

struct SocketData {
	struct {
		uint32_t* fb;
		uint32_t fbLen;
		uint32_t fbX0, fbX1;
		uint32_t fbY0, fbY1;
	}fbData;

	struct {
		char* lua;
		uint32_t luaLen;
	}luaData;

	struct {
		uint32_t time0Ms, time1Ms;
	}timeData;
};
