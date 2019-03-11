#include "Output/Output.hpp"
#include "GUI/GUI.hpp"

int main(int argc, char *argv[])
{
	GUI_module::GUI gui(argc, argv);

	//testing Output::Mouse::moveTo(int, int)
	//Output_module::Mouse* mouse = new Output_module::Mouse();
	//mouse->moveTo(1, 1);
	//delete mouse;

	return gui.WaitingStopGUI();
}
