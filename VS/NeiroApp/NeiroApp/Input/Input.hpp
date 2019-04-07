#pragma once
#pragma comment (lib,"Ws2_32.lib")

#include <QThread>
#include <QDebug>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

namespace Input_module
{
	class NetworkClient : public QThread
	{
		Q_OBJECT
	public:
		explicit NetworkClient(QString threadName);

		void run();
		~NetworkClient();

	signals:
		void InputData(int);

	private:
		QString name;   // Имя потока
	};
}
