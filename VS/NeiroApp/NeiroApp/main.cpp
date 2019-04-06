#include "Output/Mouse.hpp"
#include "Output/Keyboard.hpp"
#include "GUI/GUI.hpp"
#include "Input/Input.hpp"
#include "Settings/XMLParser.hpp"
#include "Settings/Setting.hpp"
#include <QDebug>

HANDLE LoadNoShareCursor(UINT ocr_id)
{
	HANDLE tmp = LoadImage(0, MAKEINTRESOURCE(ocr_id), IMAGE_CURSOR,
		0, 0, LR_SHARED);
	if (!tmp)
		return 0;

	return CopyImage(tmp, IMAGE_CURSOR, 0, 0, 0);
}//LoadNoShareCursor

int main(int argc, char *argv[])
{
	GUI_module::GUI gui(argc, argv);

	Output_module::Mouse mouse;
	//Output_module::Keyboard keyboard;

	//Input_module::Input input;

	Settings_module::Setting s;
	s.b = 0;
	s.dbl = 228.1337;
	s.i = 1488;
	s.str = "STRING";
	s.id = 2;

	Settings_module::XMLParser p("Settings.xml");
	p.loadXML();
	p.changeSetting(s);

	/*HANDLE hWait = LoadNoShareCursor(OCR_CROSS);
	assert(hWait);

	HANDLE hArrow = LoadNoShareCursor(OCR_NORMAL);
	assert(hArrow);

	BOOL ret = SetSystemCursor((HCURSOR)hWait, OCR_NORMAL);
	assert(ret);

	// sleep for a while so the user can play with the cursor
	Sleep(8 * 1000);

	// restore the arrow cursor
	ret = SetSystemCursor((HCURSOR)hArrow, OCR_NORMAL);
	assert(ret);

	Sleep(8 * 1000);*/

	/*mouse.changeCursor();

	Sleep(15 * 1000);

	mouse.restoreCursor();*/


	return gui.WaitingStopGUI();
}
