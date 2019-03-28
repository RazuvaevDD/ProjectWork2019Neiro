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
	Output_module::Keyboard keyboard;

	Input_module::Input input;

	Settings_module::Setting s;
	s.b = 0;
	s.dbl = 228.6;
	s.i = 1488;
	s.str = "STRING";

	Settings_module::XMLParser p("Settings.xml");
	p.loadXML();

	p.addSetting(s);

	return gui.WaitingStopGUI();
}
