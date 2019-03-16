#include "Output/Keyboard.hpp"

using namespace Output_module;

Keyboard::Keyboard()
{}

Keyboard::~Keyboard()
{}

void Keyboard::pressButton(std::string sKey)
{
	INPUT input;
	WORD vKey = getKeyCode(sKey);
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey(vKey, MAPVK_VK_TO_VSC);
	input.ki.wVk = vKey;
	SendInput(1, &input, sizeof(INPUT));
}


void Keyboard::releaseButton(std::string sKey)
{
	INPUT input;
	WORD vKey = getKeyCode(sKey);
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = MapVirtualKey(vKey, MAPVK_VK_TO_VSC);
	input.ki.wVk = vKey;
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

byte Keyboard::getKeyCode(std::string sKey)
{
	if (sKey.size() == 1 && isalpha(sKey[0]))
	{
		return byte(sKey[0]);
	}
	if (sKey == "L_CTRL")
	{
		return VK_LCONTROL;
	}
	if (sKey == "ALT")
	{
		return VK_MENU;
	}
	if (sKey == "L_WIN")
	{
		return VK_LWIN;
	}
	if (sKey == "SPACE")
	{
		return VK_SPACE;
	}
	if (sKey == "R_CTRL")
	{
		return VK_RCONTROL;
	}
	if (sKey == "L_SHIFT")
	{
		return VK_LSHIFT;
	}
	if (sKey == "CAPS_LOCK")
	{
		return VK_CAPITAL;
	}
	if (sKey == "TAB")
	{
		return VK_TAB;
	}
	if (sKey == "LEFT")
	{
		return VK_LEFT;
	}
	if (sKey == "RIGHT")
	{
		return VK_RIGHT;
	}
	if (sKey == "UP")
	{
		return VK_UP;
	}
	if (sKey == "DOWN")
	{
		return VK_DOWN;
	}
	if (sKey == "R_SHIFT")
	{
		return VK_RSHIFT;
	}
	if (sKey == "ENTER")
	{
		return VK_RETURN;
	}
	if (sKey == "NUM")
	{
		return VK_NUMLOCK;
	}
	if (sKey == "BACKSPACE")
	{
		return VK_BACK;
	}
	if (sKey == "SCROLL_LOCK")
	{
		return VK_SCROLL;
	}
	if (sKey == "PAUSE")
	{
		return VK_PAUSE;
	}
	if (sKey == "DELETE")
	{
		return VK_DELETE;
	}
	if (sKey == "PGUP")
	{
		return VK_PRIOR;
	}
	if (sKey == "PGDN")
	{
		return VK_NEXT;
	}
	if (sKey == "F1")
	{
		return VK_F1;
	}
	if (sKey == "F2")
	{
		return VK_F2;
	}
	if (sKey == "F3")
	{
		return VK_F3;
	}
	if (sKey == "F4")
	{
		return VK_F4;
	}
	if (sKey == "F5")
	{
		return VK_F5;
	}
	if (sKey == "F6")
	{
		return VK_F6;
	}
	if (sKey == "F7")
	{
		return VK_F7;
	}
	if (sKey == "F8")
	{
		return VK_F8;
	}
	if (sKey == "F9")
	{
		return VK_F9;
	}
	if (sKey == "F10")
	{
		return VK_F10;
	}
	if (sKey == "F11")
	{
		return VK_F11;
	}
	if (sKey == "F12")
	{
		return VK_F12;
	}
	if (sKey == "F12")
	{
		return VK_F12;
	}
	if (sKey == "NUM0")
	{
		return VK_NUMPAD0;
	}
	if (sKey == "NUM1")
	{
		return VK_NUMPAD1;
	}
	if (sKey == "NUM2")
	{
		return VK_NUMPAD2;
	}
	if (sKey == "NUM3")
	{
		return VK_NUMPAD3;
	}
	if (sKey == "NUM4")
	{
		return VK_NUMPAD4;
	}
	if (sKey == "NUM5")
	{
		return VK_NUMPAD5;
	}
	if (sKey == "NUM6")
	{
		return VK_NUMPAD6;
	}
	if (sKey == "NUM7")
	{
		return VK_NUMPAD7;
	}
	if (sKey == "NUM8")
	{
		return VK_NUMPAD8;
	}
	if (sKey == "NUM9")
	{
		return VK_NUMPAD9;
	}
	if (sKey == "DECIMAL")
	{
		return VK_DECIMAL;
	}
	if (sKey == "ADD")
	{
		return VK_ADD;
	}
	if (sKey == "SUBTRACT")
	{
		return VK_SUBTRACT;
	}
	if (sKey == "DIVIDE")
	{
		return VK_DIVIDE;
	}
	if (sKey == "MULTIPLY")
	{
		return VK_MULTIPLY;
	}
	if (sKey == "ESC")
	{
		return VK_ESCAPE;
	}
	if (sKey == "~")
	{
		return 192;
	}
	if (sKey == "=")
	{
		return 187;
	}
	if (sKey == "-")
	{
		return 189;
	}
	if (sKey == "0")
	{
		return 48;
	}
	if (sKey == "1")
	{
		return 49;
	}
	if (sKey == "2")
	{
		return 50;
	}
	if (sKey == "3")
	{
		return 51;
	}
	if (sKey == "4")
	{
		return 52;
	}
	if (sKey == "5")
	{
		return 53;
	}
	if (sKey == "6")
	{
		return 54;
	}
	if (sKey == "7")
	{
		return 55;
	}
	if (sKey == "8")
	{
		return 56;
	}
	if (sKey == "9")
	{
		return 57;
	}
	if (sKey == ",")
	{
		return 188;
	}
	if (sKey == ".")
	{
		return 190;
	}
	if (sKey == "/")
	{
		return 191;
	}
	if (sKey == ";")
	{
		return 196;
	}
	if (sKey == "'")
	{
		return 222;
	}
	if (sKey == "[")
	{
		return 219;
	}
	if (sKey == "]")
	{
		return 221;
	}
	if (sKey == "|")
	{
		return 220;
	}
	return 0;
}
