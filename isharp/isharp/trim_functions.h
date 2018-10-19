#pragma once
#ifndef MOUSEHAX_TRIM_FUNCTIONS
#define MOUSEHAX_TRIM_FUNCTIONS
#include "standard.h"
class trim_functions {
public:
	static void ltrim(string &s);

	// trim from end (in place)
	static void rtrim(string &s);

	// trim from both ends (in place)
	static void trim(string &s);

	// trim from start (copying)
	static string ltrim_copy(string s);

	// trim from end (copying)
	static string rtrim_copy(string s);

	// trim from both ends (copying)
	static string trim_copy(string s);
};
#endif

