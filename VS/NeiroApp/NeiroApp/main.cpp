#include "Output/Mouse.hpp"
#include "Output/Keyboard.hpp"
#include "GUI/GUI.hpp"

int main(int argc, char *argv[])
{
	GUI_module::GUI gui(argc, argv);

	//testing Output::Mouse::moveTo(int, int)
	//Output_module::Mouse* mouse = new Output_module::Mouse();
	//mouse->moveTo(1, 1);
	//delete mouse;
	Output_module::Mouse mouse;
	Output_module::Keyboard keyboard;
	/*while (true)
	{
		mouse.moveBy(1, 0);
		Sleep(10);
	}*/
	//mouse.moveTo(100, 600, 1000);

	/*int x = mouse.getCoords().x();
	int y = mouse.getCoords().y();
	Sleep(4000);
	mouse.moveBy(5000, 0);
	int xx = mouse.getCoords().x();
	int yy = mouse.getCoords().y();*/

	/*for (int i = 0; i < 7; i++)
	{
		keyboard.pressButton("K");
		Sleep(1000);
		keyboard.releaseButton("K");
	}*/

	//mouse.setCoords(100, 100, 1000);
	/*mouse.shiftCoords(100, 0, 1000);
	mouse.setCoords(0, 0, 2000);*/
	//mouse.shiftCoords(100, 100, 1000);
	//mouse.shiftCoords(-100, -1, 1000);
	mouse.shiftCoords(100, 50, 1000);
	mouse.shiftCoords(-100, -50, 1000);
	mouse.shiftCoords(-100, -1, 1000);
	//mouse.shiftCoords(-100, -1);
	return gui.WaitingStopGUI();
}
