#pragma once
#include <Windows.h>
#include <QCursor>

namespace Output_module
{
	class Mouse
	{
	public:
		Mouse();
		~Mouse();
		QPoint getCoords(); //Return QPoint structure with current coords of cursor. This coords depends on resolution of screen
		void moveTo(double x, double y); //Move cursor to x y coordinate
		void moveTo(QPoint point); //Move cursor to QPoint coordinate
		void moveTo(double x, double y, double time); //Move cursor to x y coordinate in time (ms)
		void moveBy(double x, double y); //Shift cursor by x y
		void pressLeftClick(); //Press left button of the mouse
		void releaseLeftClick(); //Release left button of the mouse
		void pressRightClick(); //Press right button of the mouse
		void releaseRightClick(); //Release right button of the mouse
	private:
		QCursor cursor;
	};
}
