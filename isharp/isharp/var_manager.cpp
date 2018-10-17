#include "stdafx.h"
#include "var_manager.h"

bool var_manager::systemVars(string name, string content) {
	try {
		if (content[0] == '"') content = PF::removeQuotes(content);
		if (name == "$using") {
			if (content == "Console") {
				usingConsole = true;

			}
			else if (content == "Console_Extra") {
				usingConsole = true;
			}
			else if (content == "Random") {
				usingRandom = true;
			}
		}
		else if (usingConsole) {
			if (name == "$Console_Hidden") {
				if (content == "true") {
					ShowWindow(GetConsoleWindow(), SW_HIDE);
				}
				else if (content == "false") {
					ShowWindow(GetConsoleWindow(), SW_SHOW);
				}
				else {
					stackoverflowclasses::error("The system variable \"$Console_Hidden\" does not recognise the value of \"" + content + "\". This variable is a bool (\"true\" or \"false\").");
				}
				return true;
			}
			else if (name == "$Console_Font_Name") {
				font_name = content;
				return true;
			}
			else if (name == "$Console_Font_Size") {
				font_size = content;
				return true;
			}
			else if (name == "$Console_Cursor_Pos_X") {
				COORD cord;
				int temp_number = atoi(content.c_str());
				cord.X = temp_number;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);

				return true;
			}
			else if (name == "$Console_Cursor_Pos_Y") {
				COORD cord;
				int temp_number = atoi(content.c_str());
				cord.Y = temp_number;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);

				return true;
			}
			else if (name == "$Console_Title") {
				SetConsoleTitle(content.c_str());
				title_name = content;
			}
			else if (name == "$Console_Width") {
				console_functions::setConsoleWidth(atoi(content.c_str()));
			}
			else if (name == "$Console_Height") {
				console_functions::setConsoleHeight(atoi(content.c_str()));
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	catch (exception e) {
		stackoverflowclasses::error("A fatal error has occured when trying to set a system variable (name = " + name + ", content = " + content + ").");
		return false;
	}
}

string var_manager::getSystemVars(string name) {
	if (usingConsole) {
		if (name == "$Console_Hidden") {
			if (IsWindowVisible(GetConsoleWindow()) != FALSE) {
				return "false";
			}
			else {
				return "true";
			}
		}
		else if (name == "$Console_Font_Name") {
			return font_name;
		}
		else if (name == "$Console_Font_Size") {
			return font_size;
		}
		else if (name == "$Console_Cursor_Pos_X") {
			HANDLE h = GetConsoleWindow();
			COORD coord = stackoverflowclasses::GetConsoleCursorPosition(h);
			return to_string(coord.X);
		}
		else if (name == "$Console_Cursor_Pos_Y") {
			HANDLE h = GetConsoleWindow();
			COORD coord = stackoverflowclasses::GetConsoleCursorPosition(h);
			return to_string(coord.Y);
		}
		else if (name == "$Console_Title") {
			return title_name;

			//ERRORS.exe
			/*
			TCHAR szOldTitle[MAX_PATH];
			DWORD t = GetConsoleTitle(szOldTitle, MAX_PATH);
			char * procID = "";
			sprintf(procID, "%d", t);
			string toReturn = procID;
			delete procID;
			return toReturn;
			*/
		}
		else if (name == "$Console_Width") {
			return to_string(console_functions::getConsoleWidth());
		}
		else if (name == "$Console_Height") {
			return to_string(console_functions::getConsoleHeight());
		}
		else {
			return "";
		}
	}
	else {
		return "";
	}
}

void var_manager::addVar(string name, string content) {
	if (systemVars(name, content)) return; // if it is a system variable than return.

	if (variables.find(name) != variables.end()) {
		variables[name] = content;
	}
	else {
		variables.insert(make_pair(name, content));
	}
}

string var_manager::getVar(string name) {
	if (getSystemVars(name) != "") return getSystemVars(name);

	if (variables.find(name) == variables.end()) stackoverflowclasses::error("The variable \"" + name + "\" does not exist in the current context."); // means theres none
	else {
		return variables[name]; // oh so there is a variable in the maps! lets get the content of the variable! so than we can use it to bake a cupcake.
	}
}
