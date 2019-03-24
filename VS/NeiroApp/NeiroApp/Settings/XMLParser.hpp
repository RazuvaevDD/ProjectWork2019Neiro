#pragma once

#include "Setting.hpp"
#include "LibXML.h"
#include <vector>
#include <fstream>

/*
USAGE:
Run constructor with name of file in argument 
If XML file does not exist you should create it with createXMLFile(const char *aName)
If XML file already exist you should load it with loadXML()
To save changes in XML file run saveXMLFile()
Each settings in XML file should have unique ID 
*/


namespace Settings_module
{

	class XMLParser
	{
	public:
		XMLParser(const char *aName);
		bool createXMLFile(const char *aName);
		bool loadXML();
		bool saveXMLFile();

		void getSettings(std::vector<Setting>& v);
		bool addSetting(Setting &s);
		bool deleteSetting(unsigned long aId);

	private:
		const char* name;
		std::vector<Setting> settings;
	};
}
