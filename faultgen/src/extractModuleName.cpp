#include <regex>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

string extractModuleName(const string &inputFileName)
{

    ifstream inputFile(inputFileName);
    string line;
    while (getline(inputFile, line))
    {
        smatch match;
        if (regex_search(line, match, regex("module\\s+([^\\s(]+)\\s*\\(")))
        {
            return match[1];
        }
    }

    //
    return "";
}