#include "Output/Output.hpp"

using namespace Output_module;

Mouse::Mouse()
{
}


Mouse::~Mouse()
{
}

POINT Mouse::getCoords()
{
	POINT p;
	GetCursorPos(&p);
	return p;
}

void Mouse::moveTo(int x, int y)
{
	mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x, y, 0, 0);
}

void Mouse::moveBy(int x, int y)
{
	mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);
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
