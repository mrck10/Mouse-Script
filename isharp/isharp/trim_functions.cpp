#include "stdafx.h"
#include "trim_functions.h"

void trim_functions::ltrim(string & s) {
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
		return !isspace(ch);
	}));
}

// trim from end (in place)

void trim_functions::rtrim(string & s) {
	s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), s.end());
}

// trim from both ends (in place)

void trim_functions::trim(string & s) {
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)

string trim_functions::ltrim_copy(string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)

string trim_functions::rtrim_copy(string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)

string trim_functions::trim_copy(string s) {
	trim(s);
	return s;
}
