#include <QDebug>

#include "Input/Input.hpp"
#include "Output/Mouse.hpp"
#include "Output/Keyboard.hpp"
#include "GUI/GUI.hpp"
#include "Settings/XMLParser.hpp"
#include "Settings/Setting.hpp"
#include "Connector/Connector.hpp"
#include "Logic/Logic.hpp"

int main(int argc, char *argv[])
{
	GUI_module::GUI*			gui				= new GUI_module::GUI(argc, argv);
	Output_module::Mouse*			mouse			= new Output_module::Mouse();
	Output_module::Keyboard*		keyboard		= new Output_module::Keyboard();
	Input_module::NetworkClient*	networkClient	= new Input_module::NetworkClient("Client connection");
	Settings_module::XMLParser*		xmlParser		= new Settings_module::XMLParser("Settings.xml");
	Logic_module::Logic*			logic			= new Logic_module::Logic();
	Connect_module::Connector*		connector		= new Connect_module::Connector(gui, mouse, keyboard, networkClient, xmlParser, logic);

	networkClient->start();


	//Settings_module::Setting s;
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

	int returnInt = gui->WaitingStopGUI();
	delete (connector);
	delete (gui);
	delete (mouse);
	delete (keyboard);
	delete (networkClient);
	delete (xmlParser);
	return returnInt;
}
