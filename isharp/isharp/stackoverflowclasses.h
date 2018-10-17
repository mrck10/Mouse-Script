#pragma once
#ifndef MOUSEHAX_STACKOVERFLOWCLASSES
#define MOUSEHAX_STACKOVERFLOWCLASSES
using namespace std;

#include "stdafx.h"
#include "standard.h"

class stackoverflowclasses
{
public:
	stackoverflowclasses();
	~stackoverflowclasses();

	// this code was taken of stackoverflow from user omniframos https://stackoverflow.com/questions/8572991/how-to-write-the-range-based-for-loop-with-argv

	static vector<string> &split(const string &s, char delimiter, vector<string> &elems);
	static vector<string> split(const string &s, char delimiter);
	static string ReplaceAll(string str, const string& from, const string& to);
	static string arrayPassArgs(vector<string> args, int pass = 0, char passChar = ' ');
	static string removeLastCharacter(string str);
	static bool contains(string s, string contain);
	static int random(int low, int high);
	void eraseSubStr(std::string & mainStr, const std::string & toErase);
	void eraseAllSubStr(std::string & mainStr, const std::string & toErase);

	//http://blog.mrroa.com/2013/06/06/tiptrick-how-to-retrieve-a-sub-string-between-two-delimiters-using-c/
	static std::string ExtractString(std::string source, std::string start, std::string end);

	static void error(string echo);
	static std::wstring s2ws(const std::string& s);
	static LPWSTR s2lp(string stzr);
	static void Send(const TCHAR *CharacterString, HWND hKeepActive);

	/*,,  0 = down & up, 1 = down , 2 = up,,  */
	static void SendVK(WORD vk, HWND hKeepActive, int iUpDown);

	static std::string execute(std::string cmd);
	static std::string encrypt(std::string msg, std::string key);
	static std::string decrypt(std::string msg, std::string key);
	static std::string wstrtostr(const std::wstring &wstr);
	static string getBetween(string first, string last, string str);
	static string ToLower(string str);
	static std::wstring ToWString(const std::string& strText);
	static COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);
};
#endif
