#pragma once
#include <Windows.h>
#include <string>
#include <ctype.h>

namespace Output_module
{
	class Keyboard
	{
	public:
		Keyboard();
		~Keyboard();
		void pressButton(std::string sKey); //input is upper english letter like "A" or button name like "CTRL"
		void releaseButton(std::string sKey);
	private:
		byte getKeyCode(std::string sKey);
	};
}
