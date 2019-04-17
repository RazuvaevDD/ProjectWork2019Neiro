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
	connect(networkClient, SIGNAL(InputDataSig(unsigned int)), logic, SLOT(newInputDataSlt(unsigned int)));
	connect(gui, SIGNAL(getUpdatedSettingsSig()), xmlParser, SLOT(getSettingsSlt()));
	connect(xmlParser, SIGNAL(updatedSettingsSig(std::vector<Settings_module::Setting>)), gui, SLOT(updatedSettingsSlt(std::vector<Settings_module::Setting>)));
	connect(gui, SIGNAL(editSettingSig(Settings_module::Setting)), xmlParser, SLOT(changeSettingSlt(Settings_module::Setting)));
	connect(xmlParser, SIGNAL(updatedSettingsSig(std::vector<Settings_module::Setting>)), logic, SLOT(updateSettings(std::vector<Settings_module::Setting>)));
	connect(logic, SIGNAL(pressKeySig(std::string)), keyboard, SLOT(pressButtonSlt(std::string)));
	connect(logic, SIGNAL(releaseKeySig(std::string)), keyboard, SLOT(releaseButtonSlt(std::string)));
	connect(logic, SIGNAL(setCoordsSig(double, double)), mouse, SLOT(setCoordsSlt(double, double)));
	connect(logic, SIGNAL(setCoordsSig(double, double, int)), mouse, SLOT(setCoordsSlt(double, double, int)));
}

Connector::~Connector()
{
	disconnect(networkClient, SIGNAL(InputDataSig(unsigned int)), logic, SLOT(newInputDataSlt(unsigned int)));
	disconnect(gui, SIGNAL(getUpdatedSettingsSig()), xmlParser, SLOT(getSettingsSlt()));
	disconnect(xmlParser, SIGNAL(updatedSettingsSig(std::vector<Settings_module::Setting>)), gui, SLOT(updatedSettingsSlt(std::vector<Settings_module::Setting>)));
	disconnect(gui, SIGNAL(editSettingSig(Settings_module::Setting)), xmlParser, SLOT(changeSettingSlt(Settings_module::Setting)));
	disconnect(xmlParser, SIGNAL(updatedSettingsSig(std::vector<Settings_module::Setting>)), logic, SLOT(updateSettings(std::vector<Settings_module::Setting>)));
	disconnect(logic, SIGNAL(pressKeySig(std::string)), keyboard, SLOT(pressButtonSlt(std::string)));
	disconnect(logic, SIGNAL(releaseKeySig(std::string)), keyboard, SLOT(releaseButtonSlt(std::string)));
	disconnect(logic, SIGNAL(setCoordsSig(double, double)), mouse, SLOT(setCoordsSlt(double, double)));
	disconnect(logic, SIGNAL(setCoordsSig(double, double, int)), mouse, SLOT(setCoordsSlt(double, double, int)));
}
