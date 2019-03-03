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
	Output_module::Keyboard keyboard;
	for (int i = 0; i < 7; i++)
	{
		keyboard.pressButton("G");
		keyboard.releaseButton("G");
		Sleep(1000);
	}
	return gui.WaitingStopGUI();
}
