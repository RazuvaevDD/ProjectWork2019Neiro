#pragma once
#include <string>

/*It's only a prototype*/

namespace Settings_module
{
	struct Setting
	{
		Setting() = default;
		unsigned long id;
		std::string str;
		double dbl;
		bool b;
		int i;
	};
}
