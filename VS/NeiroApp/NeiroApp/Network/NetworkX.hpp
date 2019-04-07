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

class NetworkX : public QThread
{
	Q_OBJECT
public:
	explicit NetworkX(QString threadName);
	
	void run();
	~NetworkX();

signals:
	void InputData(int);

private:
	QString name;   // Имя потока
};
