// isharp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "standard.h"
#include "script_handler.h"

int __stdcall _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow) {


	string argv = stackoverflowclasses::wstrtostr(stackoverflowclasses::ToWString(lpCmdLine));
	argv.erase(remove(argv.begin(), argv.end(), '\"'), argv.end());

	if (argv[0] == '-') {
		if (argv[1] = 'e') {
			vector<string> splitedArgs = stackoverflowclasses::split(argv, ' ');
			string fileName = stackoverflowclasses::arrayPassArgs(splitedArgs, 0);


			std::ifstream file(fileName);
			std::string str;
			string filec = "";
			int counter = 0;
			while (std::getline(file, str))
			{
				filec +=  str + '\n';
				counter++;
			}

			filec = stackoverflowclasses::encrypt(filec, "MSCRIPTENC01");

			ofstream myfile;
			myfile.open(fileName + ".mscriptc");
			myfile << filec;
			myfile.close();

		}
	}
	else {

		bool isencrypted = false;

		if (argv.substr(argv.find_last_of(".") + 1) == "mscriptc") {
			isencrypted = true;
		}

		std::ifstream file(argv);
		std::string str;
		vector<string> file_contetns;
		int counter = 0;
		while (std::getline(file, str))
		{
			if (isencrypted) {
				str = stackoverflowclasses::decrypt(str, "MSCRIPTENC01");
			}

			file_contetns.resize(counter + 2); // 2 to be safe :)
			file_contetns[counter] = str;
			counter++;
		}

		script_handler sh;
		sh.runScript(file_contetns, argv);
	}
	return 0;
}
