#pragma once
#define OEMRESOURCE
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
		void setCoords(double x, double y); //Move cursor to x y coordinate
		void setCoords(QPoint point); //Move cursor to QPoint coordinate
		void setCoords(QPoint point, int time); //Move cursor to QPoint coordinate in time (ms)
		void setCoords(double x, double y, int time); //Move cursor to x y coordinate in time (ms)
		void shiftCoords(double x, double y); //Shift cursor by x y
		void shiftCoords(double x, double y, int time); // Shift cursor by x y in time (ms)
		void pressLeftClick(); //Press left button of the mouse
		void releaseLeftClick(); //Release left button of the mouse
		void pressRightClick(); //Press right button of the mouse
		void releaseRightClick(); //Release right button of the mouse
		void changeCursor(); //Change system cursor
		void restoreCursor(); //Restore system cursor
	private:
		QCursor cursor;
		HANDLE LoadNoShareCursor(UINT ocr_id);
		HANDLE hHand;
		HANDLE hArrow;
	};
}
