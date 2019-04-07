#include "Output/Mouse.hpp"
#include "Output/Keyboard.hpp"
#include "GUI/GUI.hpp"
#include "Input/Input.hpp"
#include "Settings/XMLParser.hpp"
#include "Settings/Setting.hpp"
#include <QDebug>

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

	mouse.changeCursor();

	Sleep(1000 * 10);

	mouse.restoreCursor();

	return gui.WaitingStopGUI();
}
