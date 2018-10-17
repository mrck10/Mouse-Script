#pragma once
#ifndef MOUSEHAX_CLASS_VAR_MANAGER
#define MOUSEHAX_CLASS_VAR_MANAGER
#include "stdafx.h"
#include "standard.h"
#include "PF.h"
#include "console_functions.h"

class var_manager {
private:
	bool systemVars(string name, string content);
	string getSystemVars(string name);

public:
	bool usingConsole = false;
	bool usingConsoleExtra = false;
	bool usingRandom = false;
	string title_name = "Untilted Mouse Scirpt";
	string font_name = "Lucidia Console";
	string font_size = "14";
	map<string, string> variables;
	void addVar(string name, string content);
	string getVar(string name);
};
#endif
