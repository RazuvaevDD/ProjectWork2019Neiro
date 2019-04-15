#pragma once
#pragma comment (lib,"Ws2_32.lib")

#include "Input.hpp"

using namespace Input_module;

int connectSock(SOCKET CS, const struct sockaddr* sockAdd, int sizeofServerAddr)
{
	return (connect(CS, sockAdd, sizeofServerAddr));
}

NetworkClient::NetworkClient(QString threadName) :
	name(threadName){}
 
NetworkClient::~NetworkClient()
{
	terminate();
}

void NetworkClient::run()
{
	int err, maxlen = 512;  // error code
	char* recvbuf = new char[maxlen];  // input bufer
	
	while (true)
	{
		WSADATA wsaData;
		SOCKET ConnectSocket;  // socket
		sockaddr_in ServerAddr;  // server address

		bool run_flag = TRUE;

		// initialising Winsock
		WSAStartup(MAKEWORD(2, 2), &wsaData);

		// connecting to server
		ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		ServerAddr.sin_family = AF_INET;
		ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		ServerAddr.sin_port = htons(12345);

		qDebug() << "Trying to connect...";
		err = connectSock(ConnectSocket, (sockaddr*) &ServerAddr, sizeof(ServerAddr));

		while (err == SOCKET_ERROR)
		{
			err = connectSock(ConnectSocket, (sockaddr*) &ServerAddr, sizeof(ServerAddr));
		}

		qDebug() << "Connection open.";

		while (run_flag)
		{
			try
			{
				err = recv(ConnectSocket, recvbuf, maxlen, 0);
				recvbuf[err] = 0;
				std::string buferString(recvbuf);
				int data = std::stoi(buferString);
				if (err > 0)
				{
					emit InputDataSig(data);
				}
				else
				{
					qDebug() << "Connection closing...";
					break;
				}
			}
			catch (...) 
			{
				qDebug() << "Error! Reconnect...";
				break;
			}
			
		}
		// Disconnecting 
		closesocket(ConnectSocket);
		WSACleanup();
	}
	delete (recvbuf);
}
