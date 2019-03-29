#include "XMLParser.hpp"

using namespace tinyxml2;
using namespace Settings_module;

XMLParser::XMLParser(const char *aName):
name{aName},
settings{}
{
	std::fstream fs;
	fs.open(aName);
	if (fs.fail()) 
	{
		createXMLFile(aName);
	}
}

bool XMLParser::createXMLFile(const char *aName)
{
	XMLDocument file;
	return file.SaveFile(aName) == 0;
}

bool XMLParser::loadXML()
{
	XMLDocument file;
	file.LoadFile(name);
	XMLElement* root = file.RootElement();
	XMLElement* setting;
	if (root != nullptr)
	{
		setting = root->FirstChildElement();
	}
	else
	{
		return false;
	}

	settings = {};

	while (setting != nullptr)
	{
		Setting s;
		s.id = std::stoi(setting->Attribute("id"));
		s.str = setting->FirstChildElement("str")->GetText();
		s.dbl = std::stod(setting->FirstChildElement("dbl")->GetText());
		s.b = strcmp(setting->FirstChildElement("b")->GetText(), "1") == 0;
		s.i = std::stoi(setting->FirstChildElement("i")->GetText());
		settings.push_back(s);
		setting = setting->NextSiblingElement();
	}
	return true;
}

bool XMLParser::saveXMLFile()
{
	XMLDocument file;
	XMLElement *root = file.NewElement("root");

	for (const Setting &s: settings) 
	{
		XMLElement *setting = file.NewElement("setting");
		setting->SetAttribute("id", static_cast<int>(s.id));
		XMLElement *str = file.NewElement("str");
		setting->LinkEndChild(str);
		str->LinkEndChild(file.NewText(s.str.c_str()));
		XMLElement *dbl = file.NewElement("dbl");
		setting->LinkEndChild(dbl);
		dbl->LinkEndChild(file.NewText(std::to_string(s.dbl).c_str()));
		XMLElement *b = file.NewElement("b");
		setting->LinkEndChild(b);
		b->LinkEndChild(file.NewText(std::to_string(s.b).c_str()));
		XMLElement *i = file.NewElement("i");
		setting->LinkEndChild(i);
		i->LinkEndChild(file.NewText(std::to_string(s.i).c_str()));
		root->LinkEndChild(setting);
  }
	file.LinkEndChild(root);
	return file.SaveFile(name) == 0;
}

std::vector<Setting> XMLParser::getSettings()
{
	return settings;
}

bool XMLParser::addSetting(Setting &s)
{
	s.id = settings.size() + 1;
	settings.push_back(s);
	saveXMLFile();
	return true;
}

bool XMLParser::deleteSetting(unsigned long aId)
{
	for (auto it = settings.begin(); it != settings.end(); ++it)
	{
		if ((*it).id == aId)
		{
			it = settings.erase(it);
			saveXMLFile();
			return true;
		}
	}
	if (settings.size() == 0)
	{
		clearXMLFile();
	}
	return false;
}

bool XMLParser::clearXMLFile()
{
	XMLDocument file;
	settings.clear();
	return file.SaveFile(name) == 0;
}
