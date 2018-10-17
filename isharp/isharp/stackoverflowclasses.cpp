#include "stdafx.h"
#include "stackoverflowclasses.h"


stackoverflowclasses::stackoverflowclasses()
{
}


stackoverflowclasses::~stackoverflowclasses()
{
}


/*,,  0 = down & up, 1 = down , 2 = up,,  */

vector<string>& stackoverflowclasses::split(const string & s, char delimiter, vector<string>& elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delimiter)) {
		if (item.length() > 0) {
			elems.push_back(item);
		}
	}
	return elems;
}

vector<string> stackoverflowclasses::split(const string & s, char delimiter) {
	vector<string> elems;
	split(s, delimiter, elems);
	return elems;
}

string stackoverflowclasses::ReplaceAll(string str, const string & from, const string & to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
	return str;
}

string stackoverflowclasses::arrayPassArgs(vector<string> args, int pass, char passChar) {
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

string stackoverflowclasses::removeLastCharacter(string str) {
	return str.substr(0, str.length() - 1);;
}

bool stackoverflowclasses::contains(string s, string contain) {
	if (s.find(contain) != std::string::npos) {
		return true;
	}
	else {
		return false;
	}
}

int stackoverflowclasses::random(int low, int high) {
	if (low > high) return high;
	return low + (std::rand() % (high - low + 1));
}

void stackoverflowclasses::eraseSubStr(std::string & mainStr, const std::string & toErase)
{
	// Search for the substring in string
	size_t pos = mainStr.find(toErase);

	if (pos != std::string::npos)
	{
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

void stackoverflowclasses::eraseAllSubStr(std::string & mainStr, const std::string & toErase)
{
	size_t pos = std::string::npos;

	// Search for the substring in string in a loop untill nothing is found
	while ((pos = mainStr.find(toErase)) != std::string::npos)
	{
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

std::string stackoverflowclasses::ExtractString(std::string source, std::string start, std::string end)
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

void stackoverflowclasses::error(string echo) {
	cout << "ERROR : " + echo << endl;
	system("pause");
	exit(0);
}

std::wstring stackoverflowclasses::s2ws(const std::string & s)
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

LPWSTR stackoverflowclasses::s2lp(string stzr) {
	string meme = stzr;
	const char* text = meme.c_str();
	wchar_t wstr[256];
	mbstowcs(wstr, text, strlen(text) + 1);//Plus null
	LPWSTR ptr = wstr;
	return ptr;
}

void stackoverflowclasses::Send(const TCHAR * CharacterString, HWND hKeepActive)
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

void stackoverflowclasses::SendVK(WORD vk, HWND hKeepActive, int iUpDown)
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

std::string stackoverflowclasses::execute(std::string cmd) // GETS THE CMD OUTPUT...
{
	std::string file_name = "temp.mscriptdata";
	std::system((cmd + " > " + file_name).c_str()); // redirect output to file

													// open file for input, return string containing characters in the file
	std::ifstream file(file_name);
	return { std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>() };
}

std::string stackoverflowclasses::encrypt(std::string msg, std::string key)
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

std::string stackoverflowclasses::decrypt(std::string msg, std::string key)
{
	return encrypt(msg, key); // lol
}

std::string stackoverflowclasses::wstrtostr(const std::wstring & wstr)
{
	std::string strTo;
	char *szTo = new char[wstr.length() + 1];
	szTo[wstr.size()] = '\0';
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, szTo, (int)wstr.length(), NULL, NULL);
	strTo = szTo;
	delete[] szTo;
	return strTo;
}

string stackoverflowclasses::getBetween(string first, string last, string str) { // MADE BY YA BOI MRCK10 (meh)
	unsigned first_braket = str.find(first); // find the left braket
	unsigned last_braket = str.find(last); // find the right braket
	return str.substr(first_braket, last_braket - first_braket).erase(0, 1); // get the value between the brakets and remove the '(' thats leftover..
}

string stackoverflowclasses::ToLower(string str) {
	for (unsigned int i = 0; i < str.length(); ++i) {
		str = tolower(str[i]);
	}
	return str;
}

std::wstring stackoverflowclasses::ToWString(const std::string & strText)
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

COORD stackoverflowclasses::GetConsoleCursorPosition(HANDLE hConsoleOutput)
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
