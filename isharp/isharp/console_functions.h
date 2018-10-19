#pragma once
#ifndef MOUSEHAX_CONSOLE_FUNCTIONS
#define MOUSEHAX_CONSOLE_FUNCTIONS
#define _WIN32_WINNT 0x0500

#include "standard.h"

class console_functions {
public:
	static void setConsoleSize(int width, int height);
	static void setConsoleWidth(int width);
	static void setConsoleHeight(int height);
	static int getConsoleHeight();
	static int getConsoleWidth();
	static RECT getConsoleRect();
};
#endif
