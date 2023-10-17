#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdio>
#include <set>
#include "../include/numbering.hpp"
#include "../include/random.hpp"
#include "../include/ranmap.hpp"
#include "../include/filemodify.hpp"
#include "../include/extractModuleName.hpp"
#include "../include/extractVerilogNames.hpp"
#include "../include/writeVerilogModule.hpp"
#include "../include/extractCombinational.hpp"
#include "../include/faultsvector.hpp"
// #include "../include/testvectorvariable.hpp"

using namespace std;

int main()
{

    map<string, int> inputNodes;
    map<string, int> outputNodes;
    map<string, int> wireNodes;
    vector<int> inputs;
    vector<int> outputs;
    vector<int> wires;
    vector<string> testvector;
    vector<int> faultnodename;
    int value;

    const string inputFileName = "MUX32_Syn.v"; // Replace with your input Verilog file name
    const string outputFileName = "new.v";      // const string outputFileName = "EX_comb.v";   // Replace with the desired output Verilog file name
    const string newOutputFileName = "mux32fault.v";
    const string faultoutput = "muxoutfaultnodes.txt"; // const string outputFileName = "EX_comb.v";   // Replace with the desired output Verilog file name
    // const char[] name = "new.v";
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    ofstream newoutputFile(newOutputFileName);
    ofstream output2(faultoutput);

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

    // int faults;
    //  int value;
    //   vector<int> faultnodename;
    string filename = "mux32faultnodes.txt"; // Replace with the path to your text file
    vector<int> uniqueIntegers = ReadUniqueIntegersFromFile(filename);

    // Use a set to remove duplicates
    set<int> uniqueInts(uniqueIntegers.begin(), uniqueIntegers.end());

    vector<int> faultsVector(uniqueInts.begin(), uniqueInts.end());

    if (!output2.is_open())
    {
        cerr << "Error: Could not create the output file." << endl;
        return 1;
    }

    for (const auto &i : faultsVector)
    {
        output2 << i << endl;
    }

    output2.close();

    // cout << "Enter the number of fault nodes: ";
    // cin >> faults;
    cout << "Enter the stuck at value: ";
    cin >> value;
    // for (size_t i = 0; i < faults; i++)
    // {
    //     int node = random(inputs);
    //     // cout << node << endl;
    //     faultnodename.push_back(node);
    // }

    vector<string> faultnames;
    printKey(inputNodes, wireNodes, outputNodes, faultsVector, faultnames);

    for (const auto &i : faultnames)
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
