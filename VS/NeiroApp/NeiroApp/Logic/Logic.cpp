#include "Logic.hpp"
#include <QDebug>
#include <string>

using namespace Logic_module;

Logic::Logic()
{
}

Logic::~Logic()
{
}

void Logic::newInputDataSlt(int IDSignal) 
{
	qDebug() << "Input data: "<< IDSignal;
	qInfo() << settings.size();
	char str[100];
	for (unsigned int i = 0; i < settings.size(); i++)
	{
		if (IDSignal == settings[i].id)
		{
			for (unsigned int k = 0; k < settings[i].movement.size(); k++)
			{
				str[k] = settings[i].movement[k];
			}
		}
		qInfo() << str;
	}
	/*for (int i = 0; i < settings.size(); i++)
	{
		if (IDSignal == settings.at(i).id)
		{
			qInfo() << settings.at(i).movement.c_str;
		}
	}*/

}

void Logic::updateSettings(std::vector<Settings_module::Setting> settings)
{
	this->settings = settings;
}