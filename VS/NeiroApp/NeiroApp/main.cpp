#include "Output/Mouse.hpp"
#include "Output/Keyboard.hpp"
#include "GUI/GUI.hpp"
#include "Input/Input.hpp"

int main(int argc, char *argv[])
{
	GUI_module::GUI gui(argc, argv);

	Output_module::Mouse mouse;
	Output_module::Keyboard keyboard;

	Input_module::Input input;

	return gui.WaitingStopGUI();
}
