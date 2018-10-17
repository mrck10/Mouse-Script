#include "stdafx.h"
#include "PF.h"

string PF::splitColinGet(string token, int index) {
	if (token.find(":") == string::npos) return "NULL";
	vector<string> splitColin;
	splitColin.resize(20);
	splitColin = stackoverflowclasses::split(token, ':');
	if (index == 1) {
		string return_ = stackoverflowclasses::arrayPassArgs(splitColin, 0, ':');
		return return_;
	}
	return splitColin[index];
}

string PF::split(string token, char delimiter, int index) {
	if (token.find(delimiter) == string::npos) return "NULL";
	vector<string> splitColin;
	splitColin.resize(20);
	splitColin = stackoverflowclasses::split(token, delimiter);
	return splitColin[index];
}

string PF::removeQuotes(string toRemove) {
	toRemove.erase(0, 1);
	toRemove.erase(toRemove.size() - 1);
	return toRemove;
}

void PF::printVector(vector<string> vs) {
	for each (string a in vs)
	{
		cout << a << endl;
	}
}