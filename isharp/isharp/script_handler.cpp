#include "stdafx.h"
#include "script_handler.h"


script_handler::script_handler()
{
}


script_handler::~script_handler()
{
}

void script_handler::runScript(vector<string> script, string argv) {

	// allow console
	WIN32::AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);

	//cout << argv << endl;


	string scriptOne = "";
	for each (string s in script)
	{
		scriptOne += trim_functions::trim_copy(s) + '\n';
	}

	parser parser;
	vector<string> LeXed = lexer.lex(scriptOne);

	bool print_debug = false;

	if (print_debug) {
		cout << " --------------------- " << endl;
		cout << "		LEXOR " << endl;
		cout << " --------------------- " << endl;
		PF::printVector(LeXed);
		cout << " --------------------- " << endl;
		cout << "		OUTPUT " << endl;
		cout << " --------------------- " << endl;

		cout << endl << endl;
	}

	parser.parse(LeXed);
	//system("Pause");
}
