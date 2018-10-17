#pragma once
#ifndef MOUSEHAX_LEXER
#define MOUSEHAX_LEXER
#include "trim_functions.h"
class lexer {
private:
	string token; // tempary variable to use for if statments etc,

	bool string_state; // used to know if we are recording a string.
	string string_temp; // the temp string we use to temp store data.

	vector<string> tokens; // temp token list.
	int tokensCounter; // tokens counter for uses bellow..

	bool var_recording;
	bool var_str_recording;
	string var_temp;

	string int_temp;

	bool adding_recording;
	string adding_temp;

	bool label_recording;
	string label_temp;

	bool goto_recording;
	string goto_temp;

	bool goFunc_recording;
	string goFunc_temp;

	bool if_recording;

	// DEBUG SETTINGS...
	bool print_tokens = false;

	bool addTokenRemoveStarter;
	void addToken(string token);
public:
	vector<string> lex(string code);
};
#endif

