#include "Socket.hpp"

void Socket::SendMsg( int sockSendTo, const char* msg ) {
	int msgLen = strlen( msg );
	write( sockSendTo, &msgLen, sizeof( msgLen ) );

	int wr = write( sockSendTo, msg, strlen( msg ) );
	while( wr < msgLen ) {
		wr += write( sockSendTo, msg + wr, msgLen - wr );
	}
}

int Socket::RecvMsg( int sockRecvFrom, char** msg ) {
	int msgLen;
	read( sockRecvFrom, &msgLen, sizeof( msgLen ) );

	char* str = new char[msgLen + 1];

	int rd = read( sockRecvFrom, str, msgLen );
	while( rd < msgLen ) {
		rd += read( sockRecvFrom, str + rd, msgLen - rd );
	}

	*msg = str;
	return msgLen;
}

int Socket::MakeListenSocket( const char* port ) {
	int listenSock = socket( AF_INET, SOCK_STREAM, 0 );
	assert( listenSock != -1 );

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons( atoi( port ) );
	addr.sin_addr.s_addr = INADDR_ANY;

	int opt = 1;
	setsockopt( listenSock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof( opt ) );
	int bindFlag = bind( listenSock, ( struct sockaddr* )&addr, sizeof( addr ) );
	assert( bindFlag != -1 );

	int listenFlag = listen( listenSock, 5 );
	assert( listenFlag != -1 );

	return listenSock;
}
