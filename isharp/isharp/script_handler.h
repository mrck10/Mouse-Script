#pragma once
#ifndef MOUSEHAX_SCRIPT_HANDLER
#define MOUSEHAX_SCRIPT_HANDLER
using namespace std;

#include "stdafx.h"
#include "stackoverflowclasses.h"
#include "parser.h"
#include "lexer.h"


class script_handler
{
public:
	script_handler();
	~script_handler();

	lexer lexer;

	void runScript(vector<string> script, string argv);
};
#endif
