#pragma once
#pragma comment (lib,"Ws2_32.lib")

#include "Input.hpp"
#include "API/GameAPIdll.h"
#include <iostream>
using namespace Input_module;

NetworkClient::NetworkClient(QString threadName) :
	name(threadName) 
{}

NetworkClient::~NetworkClient()
{
	Disconnect();
	terminate();
}

void NetworkClient::stopClient()
{
	for (auto &stat : stats)
	{
		Stat(stat.first, stat.second.n_got, stat.second.n_tries, stat.second.n_right);
	}
	Stop();
}

void NetworkClient::request(int action_id)
{
	stats[0].n_tries++;
	unsigned int answer = Request(0);
	
	stats[action_id].n_right++;
	stats[action_id].n_got++;
	emit InputDataSig(answer);
	qDebug() << answer << "  \n";
}

void NetworkClient::updateIP_PortSlt(char* ipAddress, int port)
{
	stopClient();
	this->ipAddress = ipAddress;
	this->port = port;
	startClient();
};

void NetworkClient::start_stopProgramSlt(bool isStart)
{
	if (isStart == 1)
	{
		startClient();
		qDebug() << ">>Client started";
	}
	else if (isStart == 0)
	{
		stopClient();
		qDebug() << ">>Client stopped";
	}
};

void NetworkClient::startClient()
{
	Connect(ipAddress, port);
	qDebug() << "Connected";
	if (!(Start()))
	{
		qDebug() << "Error!";
	}
}
