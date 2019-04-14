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

void XMLParser::createXMLFile(const char *aName)
{
	XMLDocument file;
	if (file.SaveFile(aName))
	{
		qCritical() << "Unable to create XML file. Further work of the program may be incorrect. Abort recommended";
	}
}

void XMLParser::loadXML()
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
		return;
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
	getSettings();
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

void XMLParser::getSettings()
{
	emit newVector(settings);
}

void XMLParser::addSetting(Setting &s)
{
	if (settings.size() != 0)
	{
		int i = 1;
		bool flag = true;
		while (true)
		{
			for (unsigned int k = 0; k < settings.size(); k++)
			{
				if (i == settings[k].id)
				{
					flag = false;
					continue;
				}
			}
			if (flag)
			{
				s.id = i;
				break;
			}
			i++;
			flag = true;
		}
	}
	else
	{
		s.id = settings.size() + 1;
	}
	settings.push_back(s);
	saveXMLFile();
	getSettings();
}

void XMLParser::deleteSetting(unsigned long aId)
{
	for (auto it = settings.begin(); it != settings.end(); ++it)
	{
		if ((*it).id == aId)
		{
			it = settings.erase(it);
			saveXMLFile();
		}
	}
	if (settings.size() == 0)
	{
		clearXMLFile();
	}
	getSettings();
}

void XMLParser::changeSetting(Setting s)
{
	for (unsigned int i = 0; i < settings.size(); i++)
	{
		if (settings[i].id == s.id)
		{
			settings[i] = s;
			saveXMLFile();
		}
	}
	getSettings();
}

void XMLParser::clearXMLFile()
{
	XMLDocument file;
	settings.clear();
	getSettings();
	if (!file.SaveFile(name))
	{
		qCritical() << "Unable to clear XML file. Further work of the program may be incorrect. Abort recommended"; 
	}
}
