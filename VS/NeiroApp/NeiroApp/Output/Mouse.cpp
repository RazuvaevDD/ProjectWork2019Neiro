#include "Output/Mouse.hpp"
#include <cmath>
#include <QEventLoop>
#include <QTimer>

using namespace Output_module;

Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

QPoint Mouse::getCoords() 
{
	return QCursor::pos();
}

void Mouse::setCoords(double x, double y)
{
	cursor.setPos(x, y);
}

void Mouse::setCoords(QPoint point)
{
	cursor.setPos(point);
}

void Mouse::setCoords(double x, double y, double time)
{
	QPoint currentCoords = getCoords();
	double dx = abs(x - currentCoords.x());
	double dy = abs(y - currentCoords.y());
	double curX = currentCoords.x();
	double curY = currentCoords.y();
	int xMult = 1;
	int yMult = 1;
	if (curX > x)
	{
		xMult = -1;
	}
	if (curY > y)
	{
		yMult = -1;
	}
	QEventLoop loop;
	double sleepTime = time / 100;
	for (int i = 0; i < 100; i++)
	{
		curX += dx / 100 * xMult;
		curY += dy / 100 * yMult;
		cursor.setPos(curX, curY);
		QTimer::singleShot(sleepTime, &loop, SLOT(quit()));
		loop.exec();
	}
	setCoords(x, y);
}

void Mouse::shiftCoords(double x, double y)
{
	cursor.setPos(getCoords().x() + x, getCoords().y() + y);
}

void Mouse::shiftCoords(double x, double y, double time)
{
	QEventLoop loop;
	double sleepTime = time / 100;
	for (int i = 0; i < 100; i++)
	{
		shiftCoords(x / 100, y / 100);
		QTimer::singleShot(sleepTime, &loop, SLOT(quit()));
		loop.exec();
	}
}

void Mouse::pressLeftClick()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
}

void Mouse::releaseLeftClick()
{
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void Mouse::pressRightClick()
{
	mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
}

void Mouse::releaseRightClick()
{
	mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}
