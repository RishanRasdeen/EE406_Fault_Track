#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdio>
#include "numbering.hpp"
#include "random.hpp"
#include "ranmap.hpp"
#include "filemodify.hpp"
#include "extractModuleName.hpp"
#include "extractVerilogNames.hpp"
#include "writeVerilogModule.hpp"
#include "extractCombinational.hpp"
#include "testvectorvariable.hpp"

using namespace std;

int main()
{

    map<string, int> inputNodes;
    map<string, int> outputNodes;
    map<string, int> wireNodes;
    vector<int> inputs;
    vector<int> outputs;
    vector<int> wires;

    const string inputFileName = "EX_Mem_syn.v"; // Replace with your input Verilog file name
    const string outputFileName = "new.v";       // const string outputFileName = "EX_comb.v";   // Replace with the desired output Verilog file name
    const string newOutputFileName = "fault.v";  // const string outputFileName = "EX_comb.v";   // Replace with the desired output Verilog file name
    // const char[] name = "new.v";
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    ofstream newoutputFile(newOutputFileName);

    numberNodes(inputFileName, inputNodes, outputNodes, wireNodes);

    map<string, int>::iterator itr;
    for (itr = inputNodes.begin(); itr != inputNodes.end(); itr++)
    {
        // cout << itr->first << " " << itr->second << endl;
        inputs.push_back(itr->second);
    }

    for (itr = outputNodes.begin(); itr != outputNodes.end(); itr++)
    {
        // cout << itr->first << " " << itr->second << endl;
        outputs.push_back(itr->second);
    }

    for (itr = wireNodes.begin(); itr != wireNodes.end(); itr++)
    {
        // cout << itr->first << " " << itr->second << endl;
        wires.push_back(itr->second);
    }

    int faults;
    // int value;
    //  vector<int> faultnodename;

    cout << "Enter the number of fault nodes: ";
    cin >> faults;
    cout << "Enter the stuck at value: ";
    cin >> value;
    for (size_t i = 0; i < faults; i++)
    {
        int node = random(inputs);
        // cout << node << endl;
        faultnodename.push_back(node);
    }

    vector<string> faultnames;
    printKey(inputNodes, faultnodename, faultnames);

    for (const auto &i : faultnodename)
    {
        cout << i << endl;
    }
    string modulename;
    vector<string> inputPorts;
    vector<string> outputPorts;
    vector<string> wirePorts;

    modulename = extractModuleName(inputFileName);
    extractVerilogNames(inputFileName, inputPorts, outputPorts, wirePorts);
    inputPorts.push_back("f");
    writeVerilogModule(modulename, inputPorts, outputPorts, wirePorts, outputFile);
    extractCombinationalGates(inputFileName, outputFileName);
    faultfile(outputFileName, newOutputFileName, faultnames, value);

    outputFile.close();
    if (remove("new.v") == 0)
    {
        cout << "Deleted successfully" << endl;
    }
    else
    {
        cout << "Not deleted";
    }

    return 0;
}
