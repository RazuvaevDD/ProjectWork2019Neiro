#include "Logic.hpp"
#include <QDebug>
#include <string>
#include <sstream>

using namespace Logic_module;

Logic::Logic()
{
}

Logic::~Logic()
{
}

void Logic::newInputDataSlt(unsigned int IDSignal) 
{
	qDebug() << "Input data: "<< IDSignal;
	if (IDSignal > 3)
	{
		IDSignal = 3; // Only for testing. Just because we have only 4 signals 
	}
	if (IDSignal > settings.size() - 1) // ID Signal should be equal to setting position in vector
	{
		return;
	}
	if (settings[IDSignal].type == 0)
	{
		std::string str = settings[IDSignal].keys;
		int rep = 0;
		for (unsigned int i = 0; i < str.size(); i++)
		{
			if (str[i] == '+')
			{
				rep++;
				str[i] = ' ';
			}
		}
		std::vector<std::string> keys;
		std::string key;
		std::stringstream ss;
		ss << str;
		for (int i = 0; i < rep + 1; i++)
		{
			ss >> key;
			keys.push_back(key);
		}
		for (unsigned int i = 0; i < keys.size(); i++) // Now pressing keys 
		{
			emit pressKeySig(keys[i]);
		}
		for (unsigned int i = 0; i < keys.size(); i++) // Releasing keys
		{
			emit releaseKeySig(keys[i]);
		}
	}
}

void Logic::updateSettings(std::vector<Settings_module::Setting> settings)
{
	this->settings = settings;
}