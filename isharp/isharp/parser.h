#pragma once
#ifndef MOUSEHAX_PARSER
#define MOUSEHAX_PARSER
#include "stdafx.h"
#include "standard.h"
#include "var_manager.h"
#include "PF.h"
#include "trim_functions.h"
#include "keys.h"

using namespace std;

class parser
{

public:
	parser();
	~parser();

	void parse(vector<string> tokens);
};
#endif
