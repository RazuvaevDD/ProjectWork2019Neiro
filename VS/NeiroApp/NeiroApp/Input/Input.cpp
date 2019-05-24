#pragma once
#pragma comment (lib,"Ws2_32.lib")

#include "Input.hpp"
#include "API/GameAPIdll.h"
#include <iostream>
using namespace Input_module;

std::map<unsigned int, Statistics> stats;

NetworkClient::NetworkClient(QString threadName) :
	name(threadName) {}

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
	stats[action_id].n_tries++;
	unsigned int answer = Request(action_id);
	//if (answer == action_id)
	//{
	stats[action_id].n_right++;
	stats[action_id].n_got++;
	emit InputDataSig(answer);
	qDebug() << answer << "  \n";
	//}
}

void NetworkClient::updateIP_PortSlt(char* ipAddress, int port)
{
	stopClient();
	startClient(ipAddress, port);
	qDebug() << ">>Connected reconnected " << ipAddress << " " << port;
};

void NetworkClient::start_stopProgramSlt(bool isStart)
{
	qDebug() << ">>Start/Stop" << isStart;
};

void NetworkClient::startClient(char* ipAddress, int port)
{
	std::vector<unsigned int> action_id{ 42,5,5,42,5,42 };

	Connect(ipAddress, port);
	qDebug() << "Connected";
	if (!(Start()))
	{
		qDebug() << "Error! Restarting...";
	}
}
