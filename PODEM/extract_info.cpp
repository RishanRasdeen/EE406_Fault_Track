#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;

// Function to extract input, output, and wire names from a Verilog file
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
        if (regex_search(line, match, regex("input\\s*(?:\\[\\d+:\\d+\\])?\\s*([^,;]+)\\s*[,;]")))
        {
            string inputDeclaration = match[1];
            // Split the declaration into individual names
            regex wordRegex("\\b\\w+\\b");
            sregex_iterator wordIterator(inputDeclaration.begin(), inputDeclaration.end(), wordRegex);
            sregex_iterator end;
            for (; wordIterator != end; ++wordIterator)
            {
                inputPorts.push_back(wordIterator->str());
            }
        }

        // Match output declarations (e.g., output [3:0] X, Y, Z;)
        if (regex_search(line, match, regex("output\\s*(?:\\[\\d+:\\d+\\])?\\s*([^,;]+)\\s*[,;]")))
        {
            string outputDeclaration = match[1];
            // Split the declaration into individual names
            regex wordRegex("\\b\\w+\\b");
            sregex_iterator wordIterator(outputDeclaration.begin(), outputDeclaration.end(), wordRegex);
            sregex_iterator end;
            for (; wordIterator != end; ++wordIterator)
            {
                outputPorts.push_back(wordIterator->str());
            }
        }

        // Match wire declarations (e.g., wire W, X, Y, Z;)
        if (regex_search(line, match, regex("wire\\s*([^,;]+)\\s*[,;]")))
        {
            string wireDeclaration = match[1];
            // Split the declaration into individual names
            regex wordRegex("\\b\\w+\\b");
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

int main()
{
    const string inputFileName = "counter_syn.v"; // Replace with your input Verilog file name

    vector<string> inputPorts;
    vector<string> outputPorts;
    vector<string> wireNames;

    extractVerilogNames(inputFileName, inputPorts, outputPorts, wireNames);

    // Print extracted names
    cout << "Input Ports:" << endl;
    for (const string &inputPort : inputPorts)
    {
        cout << "  " << inputPort << endl;
    }

    cout << "Output Ports:" << endl;
    for (const string &outputPort : outputPorts)
    {
        cout << "  " << outputPort << endl;
    }

    cout << "Wire Names:" << endl;
    for (const string &wireName : wireNames)
    {
        cout << "  " << wireName << endl;
    }

    return 0;
}
