#pragma once
#ifndef MOUSEHAX_CLASS_PF
#define MOUSEHAX_CLASS_PF
#include "stdafx.h"
#include "standard.h"
class PF { // Parser Functions are used to parse lexer code into runtime code.
public:
	static string splitColinGet(string token, int index);
	static string split(string token, char delimiter, int index);
	static string removeQuotes(string toRemove);
	static void printVector(vector<string> vs);
};
#endif
