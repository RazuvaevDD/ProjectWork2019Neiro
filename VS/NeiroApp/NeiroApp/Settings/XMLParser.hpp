#pragma once

#include "Setting.hpp"
#include "LibXML.h"
#include <vector>
#include <fstream>

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

	class XMLParser
	{
	public:
		XMLParser(const char *aName);
		bool createXMLFile(const char *aName); // Creates new XML File
		std::vector<Setting> getSettings(); // Get vector of settings
		bool addSetting(Setting &s); // Add new setting
		bool deleteSetting(unsigned long aId); // Delete setting by ID
		bool changeSetting(Setting s); // Change setting, ID should be initialized
		bool clearXMLFile(); // Reset XML file
		bool loadXML(); // Load XML file
	private:
		bool saveXMLFile();
		const char* name;
		std::vector<Setting> settings;
	};
}
