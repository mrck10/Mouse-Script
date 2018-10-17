#include "stdafx.h"
#include "console_functions.h"

void console_functions::setConsoleSize(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

								//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
	for (int j = 0; j < 100; ++j)
	{
		for (int i = 0x41; i < 0x5B; ++i)
			cout << (char)i;
	}
	//cout << endl;
	//Sleep(1000);
	MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
}

void console_functions::setConsoleWidth(int width) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

								//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, width, r.bottom - r.top, TRUE);
}

void console_functions::setConsoleHeight(int height) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

								//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, r.right - r.left, height, TRUE);
}

int console_functions::getConsoleHeight() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	return r.bottom - r.top;
}

int console_functions::getConsoleWidth() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	return r.right - r.left;
}

RECT console_functions::getConsoleRect() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	return r;
}
