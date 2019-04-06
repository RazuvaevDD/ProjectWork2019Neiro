#include "Output/Mouse.hpp"
#include <cmath>
#include <QEventLoop>
#include <QTimer>

using namespace Output_module;

Mouse::Mouse():
	hWait(LoadNoShareCursor(OCR_HAND)),
	hArrow(LoadNoShareCursor(OCR_NORMAL))
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

void Mouse::setCoords(QPoint point, int time)
{
	setCoords(point.x(), point.y(), time);
}

void Mouse::setCoords(double x, double y, int time)
{
	if (time <= 0)
	{
		setCoords(x, y);
		return;
	}

	QPoint currentCoords = getCoords();
	double dx = abs(x - currentCoords.x());
	double dy = abs(y - currentCoords.y());
	double curX = currentCoords.x();
	double curY = currentCoords.y();
	short int xMult = 1;
	short int yMult = 1;
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

void Mouse::shiftCoords(double x, double y, int time)
{
	QPoint currentCoords = getCoords();
	double xNew = currentCoords.x() + x;
	double yNew = currentCoords.y() + y;
	setCoords(xNew, yNew, time);
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

void Mouse::changeCursor()
{
	BOOL ret = SetSystemCursor((HCURSOR)hWait, OCR_NORMAL);
	assert(ret);
}

void Mouse::restoreCursor()
{
	// restore the arrow cursor
	BOOL ret = SetSystemCursor((HCURSOR)hArrow, OCR_NORMAL);
	assert(ret);
}

HANDLE Mouse::LoadNoShareCursor(UINT ocr_id)
{
	HANDLE tmp = LoadImage(0, MAKEINTRESOURCE(ocr_id), IMAGE_CURSOR,
		0, 0, LR_SHARED);
	if (!tmp)
		return 0;

	return CopyImage(tmp, IMAGE_CURSOR, 0, 0, 0);
}//LoadNoShareCursor