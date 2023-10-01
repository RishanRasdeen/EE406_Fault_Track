#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

void numberNodes(const string &inputFileName,
                 map<string, int> &inputNodes,
                 map<string, int> &outputNodes,
                 map<string, int> &wireNodes)
{

    int count = 0;

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
                // inputPorts.push_back(wordIterator->str());
                string input = wordIterator->str();
                inputNodes[input] = count++;
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
                // outputPorts.push_back(wordIterator->str());
                string output = wordIterator->str();
                outputNodes[output] = count++;
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
                // wireNames.push_back(wordIterator->str());
                string wire = wordIterator->str();
                wireNodes[wire] = count++;
            }
        }
    }

    // Close input file
    inputFile.close();
}

// int main()
// {

//     map<string, int> inputNodes1;
//     map<string, int> outputNodes;
//     map<string, int> wireNodes;

//     const string inputFileName = "MUX32_Syn.v"; // Replace with your input Verilog file name
//                                                 // const string outputFileName = "EX_comb.v";   // Replace with the desired output Verilog file name

//     // ifstream inputFile(inputFileName);
//     //  ofstream outputFile(outputFileName);

//     numberNodes(inputFileName, inputNodes1, outputNodes, wireNodes);

//     map<string, int>::iterator itr;
//     for (itr = inputNodes1.begin(); itr != inputNodes1.end(); itr++)
//     {
//         cout << itr->first << " " << itr->second << endl;
//     }
//     return 0;
// }