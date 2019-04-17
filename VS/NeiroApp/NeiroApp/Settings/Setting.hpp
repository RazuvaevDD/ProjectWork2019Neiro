#pragma once
#include <string>

namespace Settings_module
{
	struct Setting
	{
		Setting() = default;
		unsigned long id;
		std::string movement;
		std::string keys;
		double x, y, dx, dy, mouseDelay;
		unsigned short int type; // 0 only keyboard, 1 only mouse, 2 mouse and keyboard, 3 nothing
		bool isNULL = false;
	};
}
