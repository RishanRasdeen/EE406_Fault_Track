#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "../include/extractModuleName.hpp"
#include "../include/extractVerilogNames.hpp"
#include "../include/appendAndRemove.hpp"
#include "../include/removeCommon.hpp"
#include "../include/extractCombinational.hpp"
#include "../include/writeVerilogModule.hpp"

// Struct to store flip-flop signals
struct FlipFlopSignals
{
    string clock;
    string data;
    string qOutput;
};

int main()
{
    // Define input and output file names
    const string inputFileName = "Data_Mem_syn.v"; // Replace with your input Verilog file name
    const string outputFileName = "Data_comb.v";   // Replace with the desired output Verilog file name

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the input file." << endl;
        return 1;
    }

    if (!outputFile.is_open())
    {
        cerr << "Error: Could not create the output file." << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    bool insideDFFBlock = false;
    vector<FlipFlopSignals> flipFlops;

    FlipFlopSignals currentFlipFlop;

    string moduleName; // Store the module name

    // Read input Verilog file line by line
    while (getline(inputFile, line))
    {
        if (!insideDFFBlock)
        {
            // Check if the line declares a D flip-flop (DFF)
            if (line.find("DFF") != string::npos || line.find("DFFSR") != string::npos)
            {
                insideDFFBlock = true;

                // Initialize the current flip-flop
                currentFlipFlop.clock = "";
                currentFlipFlop.data = "";
                currentFlipFlop.qOutput = "";
            }
            else
            {
                // Pass through other lines without modification
                // outputFile << line << endl;

                // Extract the module name from the line
                if (moduleName.empty())
                {
                    moduleName = extractModuleName(line);
                }
            }
        }
        else
        {
            // Check if the current line contains the clock, data, or qOutput signal
            smatch match;
            if (regex_search(line, match, regex("\\.C\\(\\s*([^,)]+)\\s*\\)")))
            {
                currentFlipFlop.clock = regex_replace(match[1].str(), regex("\\s+"), "");
            }
            if (regex_search(line, match, regex("\\.D\\(\\s*([^,)]+)\\s*\\)")))
            {
                currentFlipFlop.data = regex_replace(match[1].str(), regex("\\s+"), "");
            }
            if (regex_search(line, match, regex("\\.Q\\(\\s*([^,)]+)\\s*\\)")))
            {
                currentFlipFlop.qOutput = regex_replace(match[1].str(), regex("\\s+"), "");
            }

            // Check for the closing parenthesis of the DFF block
            if (line.find(");") != string::npos)
            {
                insideDFFBlock = false;
                flipFlops.push_back(currentFlipFlop);
            }
        }
    }

    // Close input file
    // inputFile.close();

    // Close output file
    // outputFile.close();

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

    vector<string> qOutputVector;
    vector<string> dataVector;

    for (const FlipFlopSignals &flipFlop : flipFlops)
    {
        qOutputVector.push_back(flipFlop.qOutput);
    }

    for (const FlipFlopSignals &flipFlop : flipFlops)
    {
        dataVector.push_back(flipFlop.data);
    }

    // vector<string> vector1 = {"apple", "banana", "cherry"};
    // vector<string> vector2 = {"cherry", "date", "grape"};

    // Call the function to append unique items from vector2 to vector1
    appendAndRemoveDuplicates(inputPorts, qOutputVector);
    appendAndRemoveDuplicates(outputPorts, dataVector);
    // removeCommonTerms(inputPorts, outputPorts);
    removeCommonTerms(outputPorts, inputPorts);
    removeCommonTerms(wireNames, inputPorts);
    removeCommonTerms(wireNames, outputPorts);

    // Print the modified vector1
    // cout
    //     << "Modified inputs:" << endl;
    // for (const string &term : inputPorts)
    // {
    //     cout << term << endl;
    // }
    // cout << endl;

    // cout
    //     << "Modified outputs:" << endl;
    // for (const string &term : outputPorts)
    // {
    //     cout << term << endl;
    // }
    // cout << endl;
    // cout
    //     << "Modified wires:" << endl;
    // for (const string &term : wireNames)
    // {
    //     cout << term << endl;
    // }
    // cout << endl;

    // Function to write Verilog module declaration and signals to a file
    writeVerilogModule(moduleName, inputPorts, outputPorts, wireNames, outputFile);
    extractCombinationalGates(inputFileName, outputFileName);
    // const string inputFileName = "counter_syn.v"; // Replace with your input Verilog file name

    return 0;
}
