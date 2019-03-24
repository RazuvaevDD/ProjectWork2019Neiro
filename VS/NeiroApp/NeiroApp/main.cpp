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

	Settings_module::XMLParser p("Settings.xml");

	Settings_module::Setting s;
	s.b = 0;
	s.dbl = 228;
	s.i = 1488;
	s.id = 1;
	s.str = "STRING";

	std::vector<Settings_module::Setting> settings;
	p.getSettings(settings);
	//qInfo() << settings[0].dbl;

	return gui.WaitingStopGUI();
}
