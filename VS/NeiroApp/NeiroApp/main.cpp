#include <QDebug>

#include "Input/Input.hpp"
#include "Output/Mouse.hpp"
#include "Output/Keyboard.hpp"
#include "GUI/GUI.hpp"
#include "Settings/XMLParser.hpp"
#include "Settings/Setting.hpp"

int main(int argc, char *argv[])
{
	GUI_module::GUI gui(argc, argv);
	Output_module::Mouse mouse;
	mouse.shiftCoords(100, 100);
	//Output_module::Keyboard keyboard;
	//Settings_module::Setting s;
	/*Input_module::NetworkClient networkClient("Client connection");
	networkClient.start();*/
	Settings_module::XMLParser p("set.xml");
	//s.b = 0;
	//s.dbl = 228.1337;
	//s.i = 1488;
	//s.str = "STRING";
	//s.id = 2;
	//Settings_module::XMLParser p("Settings.xml");
	//p.loadXML();
	//p.changeSetting(s);

	//mouse.changeCursor();
	//Sleep(1000 * 10);
	//mouse.restoreCursor();

	return gui.WaitingStopGUI();
}
