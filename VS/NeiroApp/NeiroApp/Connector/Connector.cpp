#include "Connector.hpp"
#include "Settings/Setting.hpp"

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
	connect(gui, SIGNAL(getUpdatedSettingsSig()), xmlParser, SLOT(getSettingsSlt()));
	connect(xmlParser, SIGNAL(updatedSettingsSig(std::vector<Settings_module::Setting>)), gui, SLOT(updatedSettingsSlt(std::vector<Settings_module::Setting>)));
}

Connector::~Connector()
{
	disconnect(networkClient, SIGNAL(InputDataSig(int)), logic, SLOT(newInputDataSlt(int)));
	disconnect(gui, SIGNAL(getUpdatedSettingsSig()), xmlParser, SLOT(getSettingsSlt()));
}
