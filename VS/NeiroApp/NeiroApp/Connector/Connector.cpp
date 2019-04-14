#include "Connector.hpp"

using namespace Connect_module;

Connector::Connector(GUI_module::GUI* gui, Output_module::Mouse* mouse, Output_module::Keyboard* kb, Input_module::NetworkClient* nc, Settings_module::XMLParser* xmlp, Logic_module::Logic* lgk)
{
	this->gui = gui;
	this->mouse = mouse;
	this->keyboard = kb;
	this->networkClient = nc;
	this->xmlParser = xmlp;
	this->logic = lgk;

	connectAll();
}

void Connector::connectAll() 
{
	connect(networkClient, SIGNAL(InputDataSig(int)), logic, SLOT(newInputDataSlt(int)));
}

Connector::~Connector()
{
	disconnect(networkClient, SIGNAL(InputDataSig(int)), logic, SLOT(newInputDataSlt(int)));
}
