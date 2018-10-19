#include "stdafx.h"
#include "lexer.h"

void lexer::addToken(string token) {
	if (print_tokens) {
		cout << token << endl;
	}
	tokensCounter++;
	tokens.resize(tokensCounter + 1);
	tokens[tokensCounter] = token;
}

vector<string> lexer::lex(string code) {
	//cout << "CODE: > " + code << endl;
	for each (char c in code)
	{
		token += c;

		if (token == " ") {
			if (label_recording) {
				addToken("LABEL" + label_temp);
				label_temp = "";
				label_recording = false;
				token = "";
			}
			else if (goFunc_recording) {
				goFunc_temp += token;
				token = "";
			}
			else if (goto_recording) {
				token = "";
			}
			else if (!string_state) {
				token = "";
			}
			if (var_temp != "" && if_recording) {
				addToken("VAR:" + var_temp);
				var_temp = "";
				var_recording = false;
			}
			else {
				string_temp += token;
				token = "";
			}
		}
		else if (c == '\n') {
			if (label_recording) {
				addToken("LABEL" + label_temp);
				label_temp = "";
				label_recording = false;
			}

			token = "";

		}
		else if (token == ";") { // if the line is over.
			if (var_temp != "") {
				addToken("VAR:" + var_temp);
				var_temp = "";
				var_recording = false;
			}
			else if (int_temp != "") {
				addToken("INT:" + int_temp);
				int_temp = "";
			}
			else if (label_recording) {
				addToken("LABEL" + label_temp);
				label_temp = "";
				label_recording = false;
			}
			else if (goFunc_recording) {
				addToken("GOFUNC:" + trim_functions::trim_copy(goFunc_temp));
				goFunc_recording = false;
				goFunc_temp = "";
			}
			else if (goto_recording) {
				addToken("GOTO");
				addToken("GODIR:" + goto_temp);
				goto_temp = "";
				goto_recording = false;
			}
			if_recording = false;
			token = "";
		}
		else if (!var_recording && !goFunc_recording && (token == "0" || token == "1" || token == "2" || token == "3" || token == "4" ||
			token == "5" || token == "6" || token == "7" || token == "8" || token == "9")) { // INT
			if (!string_state) {
				int_temp += token;
				token = "";
			}
			else {
				string_temp += token;
				token = "";
			}
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%") {
			if (!adding_recording) {
				adding_recording = true;
				adding_temp += token;
				//token = "";
			}
			else if (int_temp != "") {
				int_temp += token;
				token = "";
			}
			else {
				adding_temp += token;
				//token = "";
			}

			if (adding_temp == "++" || adding_temp == "--") {
				addToken(adding_temp);
				adding_temp = "";
				token = "";
			}
		}
		else if (var_recording && !goFunc_recording && (token == "=" || token == "+=" || token == "-=" || token == "*=" || token == "/=" || token == "%=")) {
			if (var_temp != "") {
				addToken("VAR:" + var_temp);
				var_temp = "";
				var_recording = false;
			}
			else {
				stackoverflowclasses::error("Var names cannot equal null");
			}
			if (token == "=") {
				addToken("EQUALS");
			}
			else {
				if (token == "+=") {
					addToken("+EQUALS");
				}
				else if (token == "-=") {
					addToken("-EQUALS");
				}
				else if (token == "*=") {
					addToken("*EQUALS");
				}
				else if (token == "/=") {
					addToken("/EQUALS");
				} if (token == "%=") {
					addToken("%EQUALS");
				}
			}
			token = "";
		}
		else if (token == "$" && !var_recording && !string_state && !goFunc_recording) {
			var_recording = true;
			var_temp += token;
			token = "";
		}
		else if (token == "\"" && !goFunc_recording) {
			if (!string_state) {
				string_state = true;
			}
			else if (var_recording) {
				var_str_recording = true;
				var_temp += token;
				token = "";
			}
			else {
				addToken("STRING:" + string_temp + "\"");
				string_temp = "";
				string_state = false;
				token = "";
			}
		}
		else if (label_recording) {
			label_temp += token;
			token = "";
		}
		else if (token == ":") {
			if (!string_state && !label_recording) {
				label_recording = true;
			}
		}
		else if (var_recording) {
			var_temp += token;
			token = "";
		}
		else if (string_state) {
			string_temp += token;
			token = "";
		}
		else if (goFunc_recording) {
			goFunc_temp += token;
			token = "";
		}
		else if (token == ">>" && goto_recording) {
			addToken("GOTO");
			addToken("GODIR:" + goto_temp);
			goto_temp = "";
			goto_recording = false;

			goFunc_recording = true;
			token = "";
		}
		else if (goto_recording && token != ">") { // the arrow token is for parsing arguments into gotos, (goto functions or GOFUNC)
			goto_temp += token;
			token = "";
		}
		else if (token == "goto") {
			goto_recording = true;
			token = "";
		}

		else if (token == "return") {
			addToken("RETURN");
			token = "";
		}
		else if (token == "if") {
			if_recording = true;
			addToken("IF");
			token = "";
		}
		else if (token == "else") {
			addToken("ELSE");
			token = "";
		}
		else if (token == "elif") {
			addToken("ELIF");
			token = "";
		}
		else if (token == "endif") {
			addToken("ENDIF");
			token = "";
		}

		else if (token == "Print") {
			addToken("PRINT");
			token = "";
		}
		else if (token == "Echo") {
			addToken("ECHO");
			token = "";
		}
		else if (token == "Input") {
			addToken("INPUT");
			token = "";
		}
		else if (token == "Clear" || token == "Cls") {
			addToken("CLS");
			token = "";
		}
		else if (token == "Random") {
			addToken("RANDOM");
			token = "";
		}
		else if (token == "Exit") {
			addToken("EXIT");
			token = "";
		}
		else if (token == "Pause") {
			addToken("PAUSE");
			token = "";
		}
		else if (token == "Sleep") {
			addToken("SLEEP");
			token = "";
		}
		else if (token == "Msgbox" || token == "MsgBox") {
			addToken("MSGBOX");
			token = "";
		}
		else if (token == "CMD" || token == "System") {
			addToken("CMD");
			token = "";
		}
		else if (token == "key_down") {
			addToken("ANY:KEYDOWN");
		}
		else if (token == "mouse_x") {
			addToken("ANY:XMOUSEPOS");
		}
		else if (token == "mouse_y") {
			addToken("ANY:YMOUSEPOS");
		}
		else if (token == "Console") {
			addToken("CONSOLE");
			token = "";
		}
		else if (token == "Show") {
			addToken("SHOW");
			token = "";
		}
		else if (token == "Hide") {
			addToken("HIDE");
			token = "";
		}
		else if (token == "Refresh") {
			addToken("REFRESH");
			token = "";
		}
		else if (token == "#define") {
			addToken("DEFINE");
		}
	}

	for (int i = 0; i <= 8; i++)
		addToken("EXIT"); // add the exit token at the end of the script so the application does to crash.. ( it runs out of lines and does not know what to do )
	return tokens;
}
