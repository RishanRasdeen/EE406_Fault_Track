#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void writeVerilogModule(const string &moduleName, const vector<string> &inputs, const vector<string> &outputs, const vector<string> &wires, ofstream &outputFile)
{
    // Write module declaration
    outputFile << "module " << moduleName << " (" << endl;

    // Write input ports
    for (size_t i = 0; i < inputs.size(); ++i)
    {
        outputFile << inputs[i];
        if (i < inputs.size() - 1)
            outputFile << ", ";
        else if (!outputs.empty() || !wires.empty())
            outputFile << ","; // Add a comma if there are outputs or wires
        outputFile << endl;
    }

    // Write output ports
    for (size_t i = 0; i < outputs.size(); ++i)
    {
        outputFile << outputs[i];
        if (i < outputs.size() - 1)
            outputFile << ", ";
        // else if (!wires.empty())
        //     outputFile << ","; // Add a comma if there are wires
        outputFile << endl;
    }

    // Close module declaration
    outputFile << ");" << endl;

    // Write wire declarations
    for (size_t i = 0; i < wires.size(); ++i)
    {
        outputFile << "  wire " << wires[i] << ";" << endl;
    }
    for (size_t i = 0; i < inputs.size(); ++i)
    {
        outputFile << "  input " << inputs[i] << ";" << endl;
    }
    for (size_t i = 0; i < outputs.size(); ++i)
    {
        outputFile << "  output " << outputs[i] << ";" << endl;
    }

    // Close input file

    // outputFile.close();
}