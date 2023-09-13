#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Define input and output file names
    const string inputFileName = "counter_syn.v";          // Replace with your input Verilog file name
    const string outputFileName = "output_verilog_file.v"; // Replace with the desired output Verilog file name

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

    // Read input Verilog file line by line
    while (getline(inputFile, line))
    {
        if (!insideDFFBlock)
        {
            // Check if the line declares a D flip-flop (DFF)
            if (line.find("DFF") != string::npos)
            {
                insideDFFBlock = true;
            }
            else
            {
                // Pass through other lines without modification
                outputFile << line << endl;
            }
        }
        else
        {
            // Check for the closing parenthesis of the DFF block
            if (line.find(");") != string::npos)
            {
                insideDFFBlock = false;
            }
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "D flip-flops removed successfully." << endl;

    return 0;
}
