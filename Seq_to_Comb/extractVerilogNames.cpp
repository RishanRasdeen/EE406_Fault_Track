#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

void extractVerilogNames(const string &inputFileName,
                         vector<string> &inputPorts,
                         vector<string> &outputPorts,
                         vector<string> &wireNames)
{
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the input file." << endl;
        return;
    }

    string line;

    while (getline(inputFile, line))
    {
        // Use regular expressions to match input, output, and wire declarations
        smatch match;

        // Match input declarations (e.g., input [7:0] A, B, C;)
        if (regex_search(line, match, regex(R"(input\s*(?:\[\d+(?::\d+)?\])?\s*([^,;]+)\s*[,;])")))
        {
            string inputDeclaration = match[1];
            // Split the declaration into individual names
            regex wordRegex(R"((?:\\?\w+(?:\[\d+(?::\d+)?\])*(?:\[\d+(?::\d+)?\])?)+)"); // Capture signal names with escape characters and array indices
            sregex_iterator wordIterator(inputDeclaration.begin(), inputDeclaration.end(), wordRegex);
            sregex_iterator end;
            for (; wordIterator != end; ++wordIterator)
            {
                inputPorts.push_back(wordIterator->str());
            }
        }

        // Match output declarations (e.g., output [3:0] X, Y, Z;)
        if (regex_search(line, match, regex(R"(output\s*(?:\[\d+(?::\d+)?\])?\s*([^,;]+)\s*[,;])")))
        {
            string outputDeclaration = match[1];
            // Split the declaration into individual names
            regex wordRegex(R"((?:\\?\w+(?:\[\d+(?::\d+)?\])*(?:\[\d+(?::\d+)?\])?)+)"); // Capture signal names with escape characters and array indices
            sregex_iterator wordIterator(outputDeclaration.begin(), outputDeclaration.end(), wordRegex);
            sregex_iterator end;
            for (; wordIterator != end; ++wordIterator)
            {
                outputPorts.push_back(wordIterator->str());
            }
        }

        // Match wire declarations (e.g., wire W, X, Y, Z;)
        if (regex_search(line, match, regex(R"(wire\s*(?:\[\d+(?::\d+)?\])?\s*([^,;]+)\s*[,;])")))
        {
            string wireDeclaration = match[1];
            // Split the declaration into individual names
            regex wordRegex(R"((?:\\?\w+(?:\[\d+(?::\d+)?\])*(?:\[\d+(?::\d+)?\])?)+)"); // Capture signal names with escape characters and array indices
            sregex_iterator wordIterator(wireDeclaration.begin(), wireDeclaration.end(), wordRegex);
            sregex_iterator end;
            for (; wordIterator != end; ++wordIterator)
            {
                wireNames.push_back(wordIterator->str());
            }
        }
    }

    // Close input file
    inputFile.close();
}