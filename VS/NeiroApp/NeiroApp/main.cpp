#include <QDebug>

#include "Input/Input.hpp"
#include "Output/Mouse.hpp"
#include "Output/Keyboard.hpp"
#include "GUI/GUI.hpp"
#include "Settings/XMLParser.hpp"
#include "Settings/Setting.hpp"
#include "Connector/Connector.hpp"
#include "Logic/Logic.hpp"
#include "Audio/Audio.hpp"

int main(int argc, char *argv[])
{
	GUI_module::GUI*				gui				= new GUI_module::GUI(argc, argv);
	Output_module::Mouse*			mouse			= new Output_module::Mouse();
	Output_module::Keyboard*		keyboard		= new Output_module::Keyboard();
	Input_module::NetworkClient*	networkClient	= new Input_module::NetworkClient("Client connection");
	Settings_module::XMLParser*		xmlParser		= new Settings_module::XMLParser("Settings.xml");
	Logic_module::Logic*			logic			= new Logic_module::Logic();
	Connect_module::Connector*		connector		= new Connect_module::Connector(gui, mouse, keyboard, networkClient, xmlParser, logic);
	Audio_module::Audio* audio = new Audio_module::Audio("WOO.mp3");

	audio->playSlt();


	networkClient->start();
	xmlParser->loadXMLSlt();


	/*Settings_module::Setting s;
	s.movement = "setting";
	s.dx = 1;
	s.dy = 2;
	s.isNULL = 0;
	s.keys = "4e";
	s.mouseDelay = 33;
	s.x = 1.1488;
	s.y = 228;
	s.type = 1;
	xmlParser->addSettingSlt(s);*/
	
	int returnInt = gui->WaitingStopGUI();
	delete (connector);
	delete (gui);
	delete (mouse);
	delete (keyboard);
	delete (networkClient);
	delete (xmlParser);
	return returnInt;
}
