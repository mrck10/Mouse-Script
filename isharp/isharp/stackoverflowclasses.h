#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <fstream>
#include <algorithm> 
#include <cctype>
#include <ctime>
#include <random>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>
using namespace std;

#include "stdafx.h"

class argv_range {
public:
	argv_range(int argc, const char * const argv[])
		: argc_(argc), argv_(argv)
	{
	}

	const char * const *begin() const { return argv_; }
	const char * const *end() const { return argv_ + argc_; }

private:
	const int argc_;
	const char * const *argv_;
};


class trim_functions {
public:
	static inline void ltrim(string &s) {
		s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
			return !isspace(ch);
		}));
	}

	// trim from end (in place)
	static inline void rtrim(string &s) {
		s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
			return !isspace(ch);
		}).base(), s.end());
	}

	// trim from both ends (in place)
	static inline void trim(string &s) {
		ltrim(s);
		rtrim(s);
	}

	// trim from start (copying)
	static inline string ltrim_copy(string s) {
		ltrim(s);
		return s;
	}

	// trim from end (copying)
	static inline string rtrim_copy(string s) {
		rtrim(s);
		return s;
	}

	// trim from both ends (copying)
	static inline string trim_copy(string s) {
		trim(s);
		return s;
	}
};

class stackoverflowclasses
{
public:
	stackoverflowclasses();
	~stackoverflowclasses();

	// this code was taken of stackoverflow from user omniframos https://stackoverflow.com/questions/8572991/how-to-write-the-range-based-for-loop-with-argv

	static vector<string> &split(const string &s, char delim, vector<string> &elems) {
		stringstream ss(s);
		string item;
		while (getline(ss, item, delim)) {
			if (item.length() > 0) {
				elems.push_back(item);
			}
		}
		return elems;
	}

	static vector<string> split(const string &s, char delim) {
		vector<string> elems;
		split(s, delim, elems);
		return elems;
	}

	static string ReplaceAll(string str, const string& from, const string& to) {
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
		}
		return str;
	}

	static string arrayPassArgs(vector<string> args, int pass = 0, char passChar = ' ') {
		string toProduce = "";
		int max = pass;
		int counter = 0;
		for each (string s in args)
		{
			if (counter > max) {
				toProduce += args[counter] + passChar;
			}
			counter++;
		}
		return removeLastCharacter(toProduce);
	}

	static string removeLastCharacter(string str) {
		return str.substr(0, str.length() - 1);;
	}

	static bool contains(string s, string contain) {
		if (s.find(contain) != std::string::npos) {
			return true;
		}
		else {
			return false;
		}
	}

	static int random(int low, int high) {
		if (low > high) return high;
		return low + (std::rand() % (high - low + 1));
	}

	void eraseSubStr(std::string & mainStr, const std::string & toErase)
	{
		// Search for the substring in string
		size_t pos = mainStr.find(toErase);

		if (pos != std::string::npos)
		{
			// If found then erase it from string
			mainStr.erase(pos, toErase.length());
		}
	}

	void eraseAllSubStr(std::string & mainStr, const std::string & toErase)
	{
		size_t pos = std::string::npos;

		// Search for the substring in string in a loop untill nothing is found
		while ((pos = mainStr.find(toErase)) != std::string::npos)
		{
			// If found then erase it from string
			mainStr.erase(pos, toErase.length());
		}
	}

	//http://blog.mrroa.com/2013/06/06/tiptrick-how-to-retrieve-a-sub-string-between-two-delimiters-using-c/

	static std::string ExtractString(std::string source, std::string start, std::string end)
	{
		std::size_t startIndex = source.find(start);

		// Adding the length of the delimiter to our starting index
		// this will move us to the beginning of our sub-string.
		//
		startIndex += start.length();

		// Looking for the end delimiter
		//
		std::string::size_type endIndex = source.find(end, startIndex);

		// Returning the substring between the start index and
		// the end index. If the endindex is invalid then the
		// returned value is empty string
		return source.substr(startIndex, endIndex - startIndex);
	}

	static void error(string echo) {
		cout << "ERROR : " +  echo << endl;
		system("pause");
		exit(0);
	}


	static std::wstring s2ws(const std::string& s)
	{
		int len;
		int slength = (int)s.length() + 1;
		len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
		wchar_t* buf = new wchar_t[len];
		MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
		std::wstring r(buf);
		delete[] buf;
		return r;
	}

	static LPWSTR s2lp(string stzr) {
		string meme = stzr;
		const char* text = meme.c_str();
		wchar_t wstr[256];
		mbstowcs(wstr, text, strlen(text) + 1);//Plus null
		LPWSTR ptr = wstr;
		return ptr;
	}

	static void Send(const TCHAR *CharacterString, HWND hKeepActive)
	{
		TCHAR cChar, FiLoBuffer[32];
		INPUT Input = { 0 };
		KEYBDINPUT kb = { 0 };
		int iModifiers = 0;
		int iUpDown = 0;
		BOOL bNoMoreModifier;

		cChar = *CharacterString;
		BlockInput(TRUE);
		while ((cChar))
		{
			if (hKeepActive != NULL)
			{
				if (IsIconic(hKeepActive)) ShowWindow(hKeepActive, SW_RESTORE);
				if (hKeepActive != GetForegroundWindow()) SetForegroundWindow(hKeepActive);
			}
			ZeroMemory(&kb, sizeof(KEYBDINPUT));
			bNoMoreModifier = FALSE;
			switch (cChar)
			{
			case '!':
				kb.wVk = VK_MENU;
				FiLoBuffer[iModifiers++] = VK_MENU;
				break;
			case '+':
				kb.wVk = VK_SHIFT;
				FiLoBuffer[iModifiers++] = VK_SHIFT;
				break;
			case '^':
				kb.wVk = VK_CONTROL;
				FiLoBuffer[iModifiers++] = VK_CONTROL;
				break;
			case '#':
				kb.wVk = VK_RWIN;
				FiLoBuffer[iModifiers++] = VK_RWIN;
				break;
			default:
				bNoMoreModifier = TRUE;
				break;
			}

			if ((iModifiers > 0) && bNoMoreModifier) //First char after modifierer
			{
				if ((cChar > 0x60) && (cChar < 0x7b))
					kb.wVk = cChar - 0x20;
				else
					kb.wVk = cChar;

				kb.wScan = 0;
			}
			else if (iModifiers > 0)
			{
				kb.wScan = 0;
			}
			else
			{
				kb.wVk = 0;
				kb.wScan = cChar;
			}
			kb.dwFlags = KEYEVENTF_UNICODE;
			Input.type = INPUT_KEYBOARD;
			Input.ki = kb;
			SendInput(1, &Input, sizeof(Input));

			if ((iModifiers == 0) || (bNoMoreModifier))
			{
				if (iModifiers != 0)
				{
					if ((cChar > 0x60) && (cChar < 0x7b))
						kb.wVk = cChar - 0x20;
					else
						kb.wVk = cChar;
					kb.wScan = 0;
				}
				else
				{
					kb.wVk = 0;
					kb.wScan = cChar;
				}
				kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
				Input.type = INPUT_KEYBOARD;
				Input.ki = kb;
				SendInput(1, &Input, sizeof(Input));
			}

			if ((bNoMoreModifier || (CharacterString[1] == NULL)) && (iModifiers > 0))
			{
				for (int i = iModifiers - 1; i >= 0; i--)
				{
					kb.wVk = FiLoBuffer[i];
					kb.wScan = 0;
					kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
					Input.type = INPUT_KEYBOARD;
					Input.ki = kb;
					SendInput(1, &Input, sizeof(Input));
					FiLoBuffer[i] = 0;
				}
				iModifiers = 0;
			}

			cChar = *++CharacterString;
		}
		BlockInput(FALSE);
	}

	/*,,  0 = down & up, 1 = down , 2 = up,,  */
	static void SendVK(WORD vk, HWND hKeepActive, int iUpDown)
	{
		INPUT Input = { 0 };
		KEYBDINPUT kb = { 0 };

		if (hKeepActive != NULL)
		{
			if (IsIconic(hKeepActive)) ShowWindow(hKeepActive, SW_RESTORE);
			if (hKeepActive != GetForegroundWindow()) SetForegroundWindow(hKeepActive);
		}

		if ((iUpDown == 0) || (iUpDown == 1))
		{
			kb.wVk = vk;
			kb.wScan = 0;
			kb.dwFlags = KEYEVENTF_UNICODE;
			Input.type = INPUT_KEYBOARD;
			Input.ki = kb;
			SendInput(1, &Input, sizeof(Input));
		}

		if ((iUpDown == 0) || (iUpDown == 2))
		{
			kb.wVk = vk;
			kb.wScan = 0;
			kb.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
			Input.type = INPUT_KEYBOARD;
			Input.ki = kb;
			SendInput(1, &Input, sizeof(Input));
		}
	}

	static std::string execute(std::string cmd) // GETS THE CMD OUTPUT...
	{
		std::string file_name = "temp.mscriptdata";
		std::system((cmd + " > " + file_name).c_str()); // redirect output to file

														// open file for input, return string containing characters in the file
		std::ifstream file(file_name);
		return { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
	}

	static std::string encrypt(std::string msg, std::string key)
	{
		// Make sure the key is at least as long as the message
		std::string tmp(key);
		while (key.size() < msg.size())
			key += tmp;

		// And now for the encryption part
		for (std::string::size_type i = 0; i < msg.size(); ++i)
			msg[i] ^= key[i];
		return msg;
	}
	static std::string decrypt(std::string msg, std::string key)
	{
		return encrypt(msg, key); // lol
	}

	static std::string wstrtostr(const std::wstring &wstr)
	{
		std::string strTo;
		char *szTo = new char[wstr.length() + 1];
		szTo[wstr.size()] = '\0';
		WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, szTo, (int)wstr.length(), NULL, NULL);
		strTo = szTo;
		delete[] szTo;
		return strTo;
	}

	static string getBetwwen(string first, string last, string str) { // MADE BY YA BOI MRCK10 (meh)
		unsigned first_braket = str.find(first); // find the left braket
		unsigned last_braket = str.find(last); // find the right braket
		return str.substr(first_braket, last_braket - first_braket).erase(0, 1); // get the value between the brakets and remove the '(' thats leftover..
	}

	static string ToLower(string str) {
		for (unsigned int i = 0; i < str.length(); ++i) {
			str = tolower(str[i]);
		}
		return str;
	}

	static std::wstring ToWString(const std::string& strText)
	{
		std::wstring      wstrResult;

		wstrResult.resize(strText.length());

		typedef std::codecvt<wchar_t, char, mbstate_t> widecvt;

		std::locale     locGlob;

		std::locale::global(locGlob);

		const widecvt& cvt(std::use_facet<widecvt>(locGlob));

		mbstate_t   State;

		const char* cTemp;
		wchar_t*    wTemp;

		cvt.in(State,
			&strText[0], &strText[0] + strText.length(), cTemp,
			(wchar_t*)&wstrResult[0], &wstrResult[0] + wstrResult.length(), wTemp);

		return wstrResult;
	}

	static COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
	{
		CONSOLE_SCREEN_BUFFER_INFO cbsi;
		if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
		{
			return cbsi.dwCursorPosition;
		}
		else
		{
			// The function failed. Call GetLastError() for details.
			COORD invalid = { 0, 0 };
			return invalid;
		}
	}


};

class keys {
public:


	static string save(char &_key) {
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

	static string logger(int type) {
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

};

class Random { // simple (not random) random class made by ya boi ( uses some random math i made to "make" a random
private:
	int seed_temp1 = 1934;
	int seed_temp2 = 92;
	int seed_temp3 = 124;

	bool used1 = false;
	bool used2 = false;

	int count_seed = 1;

	int getRandom() {
		srand(time(NULL));
		return rand() % 129;
	}

public:

	int seed1 = 1934;
	int seed2 = 295;
	int seed3 = 900; // 

	int multiplyer = 123;

	string random_int(int min, int max) {
		int random = (((seed_temp1 * seed_temp2 * count_seed) - seed_temp3 * getRandom()) / count_seed) * max / 999999 + 1 + min;

		if (random % 2 == 0) { // is an even number...
			if (random * 2 > max) {
				if ((random + (random / 3) * 2) < max) {
					random += (random / 3) * 2;
				}
			}
			else {
				random *= 2;
			}
		}
		else {
			if (random / 2 < min) {

			}
			else {
				random = random / 2;
			}
		}

		if (random > max) {
			random -= max / 10;

			// if the random won't shrink..
			while (random > max) {
				random -= max / 10;
			}
		}

		if (!used2)
			seed_temp1 -= seed2;
		else
			seed_temp1 += seed2;

		seed_temp2 += 3;

		seed_temp3 -= 5;

		if (seed_temp1 > 3000) {
			seed_temp1 = seed1;
			seed_temp2 = seed2;
			seed_temp3 = seed3;
			used1 = false;
			used2 = false;
			count_seed++;
			if (count_seed == 5) {
				count_seed = 1;
			}
		}


		if (seed_temp1 <= 1000 && !used1) {
			seed_temp1 += seed1;
			used1 = true;
		}
		else if (seed_temp1 <= 900 && !used2) {
			used2 = true;
		}

		return to_string(random);
	}




	string rand_here(int min, int max) {
		return to_string(rand() % max + min);
	}
};


class console_functions {
public:
#define _WIN32_WINNT 0x0500

	static void setConsoleSize(int width, int height) {
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

	static void setConsoleWidth(int width) {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions

									//MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, r.left, r.top, width, r.bottom - r.top, TRUE);
	}

	static void setConsoleHeight(int height) {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions

									//MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, r.left,r.top,  r.right - r.left, height, TRUE);
	}

	static int getConsoleHeight() {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		return r.bottom - r.top;
	}

	static int getConsoleWidth() {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		return r.right - r.left;
	}

	static RECT getConsoleRect() {
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r);
		return r;
	}
};
