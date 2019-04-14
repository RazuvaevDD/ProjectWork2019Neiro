#pragma once

#include "Setting.hpp"
#include "LibXML.h"
#include <vector>
#include <fstream>
#include <QObject>
#include <QDebug>
/*
USAGE:
Run constructor with name of file in argument
If file does not exist it will be created
Run loadXML function
To add new setting in XML run addSetting(Setting &s)
To get vector of settings run getSettings()
To change setting run changeSetting(Setting s)
Each settings in XML file should have unique ID 
*/


namespace Settings_module
{
	class XMLParser : QObject
	{
		Q_OBJECT
	public:
		XMLParser(const char *aName);
		~XMLParser();

	public slots:

		void createXMLFile(const char *aName); // Creates new XML File
		void getSettings(); // Get vector of settings
		void addSetting(Setting &s); // Add new setting
		void deleteSetting(unsigned long aId); // Delete setting by ID
		void changeSetting(Setting s); // Change setting, ID should be initialized
		void clearXMLFile(); // Reset XML file
		void loadXML(); // Load XML file

	signals:
		void newVector(std::vector<Setting> v);

	private:
		bool saveXMLFile();
		const char* name;
		std::vector<Setting> settings;
	};
}
