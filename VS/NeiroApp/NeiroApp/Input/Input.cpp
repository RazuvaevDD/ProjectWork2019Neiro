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
	while (true)
	{
		WSADATA wsaData;
		SOCKET ConnectSocket; // Input socket and socket for clients
		sockaddr_in ServerAddr; // Address of server
		int err = 0;  // Error code and buffer size
		const int maxlen = 512;
		//char* recvbuf = new char[maxlen]; // Input buffer
		char recvbuf[maxlen];

		bool run_flag = TRUE;

		// Winsock initialization
		WSAStartup(MAKEWORD(2, 2), &wsaData);

		// Connecting to server
		ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		ServerAddr.sin_family = AF_INET;
		ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		ServerAddr.sin_port = htons(12345);

		qDebug() << "Trying to connect...";
		err = connectSock(ConnectSocket, (sockaddr *)&ServerAddr, sizeof(ServerAddr));

		while (err == SOCKET_ERROR)
		{
			err = connectSock(ConnectSocket, (sockaddr *)&ServerAddr, sizeof(ServerAddr));
		}

		qDebug() << "Connection open.";

		while (run_flag)
		{
			try 
			{
				err = recv(ConnectSocket, recvbuf, maxlen, 0);
				recvbuf[err] = 0;
				std::string stroka(recvbuf);
				int data = std::stoi(stroka);
				if (err > 0) 
				{
					qDebug() << "Data: " << data ;
					emit InputData(data);
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
}
