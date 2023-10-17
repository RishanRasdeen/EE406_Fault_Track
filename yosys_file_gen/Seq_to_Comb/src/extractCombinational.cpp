#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

void extractCombinationalGates(const string &inputFileName, const string &outputFileName)
{
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName, ios_base::app);

    if (!inputFile.is_open())
    {
        cerr << "Error: Could not open the input file." << endl;
        return;
    }

    if (!outputFile.is_open())
    {
        cerr << "Error: Could not create the output file." << endl;
        return;
    }

    vector<string> lines;
    string line;
    bool startReading = false;   // Flag to indicate when to start reading
    bool insideDFFBlock = false; // Flag to indicate when inside a DFF block

    // Read input Verilog file line by line
    while (getline(inputFile, line))
    {
        // Check if the line contains "module" (indicating the module declaration)
        if (line.find("module") != string::npos)
        {
            // Skip module declaration
            startReading = false;
        }

        // Check if the line contains "input" or "output" (indicating ports)
        if (line.find("input") != string::npos || line.find("output") != string::npos || line.find("wire") != string::npos)
        {
            // Skip ports
        }

        // Check if the line contains "DFF" (indicating a D flip-flop gate)
        else if (line.find("DFF") != string::npos || line.find("DFFSR") != string::npos)
        {
            // Set the insideDFFBlock flag when entering a DFF block
            insideDFFBlock = true;
            // Skip the DFF line
            continue;
        }

        // Check if the line contains gates (e.g., "AND", "OR", "NAND", "NOR", "XOR")
        else if (line.find("AND") != string::npos || line.find("OR") != string::npos ||
                 line.find("NAND") != string::npos || line.find("NOR") != string::npos ||
                 line.find("XOR") != string::npos || line.find("NOT") != string::npos)
        {
            // Only start reading if not inside a DFF block
            if (!insideDFFBlock)
            {
                startReading = true; // Start reading from the first gate
            }
        }

        // Check if the line marks the end of a DFF block
        else if (insideDFFBlock && line.find(");") != string::npos)
        {
            insideDFFBlock = false; // Reset the insideDFFBlock flag
        }

        // Continue reading if the flag is set
        if (startReading)
        {
            // Pass through other lines without modification (combinational gates)
            outputFile << line << endl;

            // Check if the line ends with a semicolon and marks the end of a gate
            if (line.back() == ';')
            {
                startReading = false; // Stop reading after the gate
            }
        }
    }

    outputFile << "endmodule" << endl;
    // Close input file
    inputFile.close();

    // Close output file
    outputFile.close();
}

// int main()
// {
//     const string inputFileName = "IF_ID_syn.v";            // Replace with your input Verilog file name
//     const string outputFileName = "combinational_gates.v"; // Replace with the desired output file name

//     extractCombinationalGates(inputFileName, outputFileName);

//     // Rest of your code...

//     return 0;
// }
