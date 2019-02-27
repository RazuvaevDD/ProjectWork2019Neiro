#pragma once
#include <Windows.h>
class Mouse
{
public:
	Mouse();
	~Mouse();
	POINT getCoords(); //Return POINT (Defined in Windows.h) structure with current coords of cursor
	//Upper left corner is a {0;0}. Lower right corner is {65535; 65535}
	void moveTo(int x, int y); //Move cursor to x y coordinate 
	void moveBy(int x, int y); //Shift cursor by x y
	void pressLeftClick(); //Press left button of the mouse
	void releaseLeftClick(); //Release left button of the mouse
	void pressRightClick(); //Press right button of the mouse
	void releaseRightClick(); //Release right button of the mouse
};

