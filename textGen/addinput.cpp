#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

void addinput(const string &inputFileName, const string &outputFileName)
{

    ifstream inputfile(inputFileName);
    ofstream outputfile(outputFileName);

    string line;
    bool insideModule = false;
    vector<string> modulelines;
    string newInput = "f";

    while (getline(inputfile, line))
    {
        if (regex_search(line, regex("module\\s+\\w+\\s*\\(")))
        {
            insideModule = true; // Set the flag to indicate we are inside a module
        }

        // Check if we are inside a module
        if (insideModule)
        {
            if (line.find(");") != std::string::npos)
            {
                // Found the closing bracket of the module definition
                modulelines.push_back(newInput); // Add the new input declaration
                insideModule = false;            // Reset the flag as we are no longer inside a module
            }
        }

        modulelines.push_back(line);
        inputfile.close();
    }

    for (const auto &i : modulelines)
    {
        outputfile << i << endl;
    }
}