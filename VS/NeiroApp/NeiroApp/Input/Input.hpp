#pragma once

#include <QThread>
#include <QDebug>

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

namespace Input_module
{
	struct Statistics
	{
		unsigned int n_got = 0;
		unsigned int n_tries = 0;
		unsigned int n_right = 0;
	};

	class NetworkClient : public QThread
	{
		Q_OBJECT
	public:
		explicit NetworkClient(QString threadName);

		void startClient();

		void request(int);

		void stopClient();

		~NetworkClient();

	public slots:
		void updateIP_PortSlt(char*, int);
		void start_stopProgramSlt(bool);

	signals:
		void InputDataSig(unsigned int);

	private:
		QString name;
		std::map<unsigned int, Statistics> stats;
		// Default values:
		char* ipAddress = "127.0.0.1";
		int port = 2121;
	};
}
