#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>
#include <vector>

using namespace std;

string executeYosysCommands(vector<string>& commands) {
    string result;

    // Open a single pipe to the Yosys process
    FILE* pipe = popen("yosys", "w");

    if (!pipe) {
        throw runtime_error("Failed to open Yosys pipe.");
    }

    // Send each Yosys command to the pipe
    for (const string& command : commands) {
        fprintf(pipe, "%s\n", command.c_str());
        fflush(pipe);
    }

    // Read the output from the Yosys process
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    // Close the pipe
    pclose(pipe);

    return result;
}

int main() {
    try {
        // Example: Run a Yosys command to read a Verilog file
        string verilogFile = "counter.v";
        string yosysCommand1 = "read_verilog " + verilogFile;
        string yosysCommand2 = "splitnets -ports";
        string yosysCommand3 = "read_verilog -lib cmos_cells.v";
        string yosysCommand4 = "synth";
        string yosysCommand5 = "dfflibmap -liberty cmos_cells.lib";
        string yosysCommand6 = "abc -liberty cmos_cells.lib";
        string yosysCommand7 = "opt_clean";
        string yosysCommand8 = "stat -liberty cmos_cells.lib";
        string yosysCommand9 = "write_verilog synth.v";
        
        vector<string> yosyscommands;
        
        yosyscommands.push_back(yosysCommand1);
        yosyscommands.push_back(yosysCommand2);
        yosyscommands.push_back(yosysCommand3);
        yosyscommands.push_back(yosysCommand4);
        yosyscommands.push_back(yosysCommand5);
        yosyscommands.push_back(yosysCommand6);
        yosyscommands.push_back(yosysCommand7);
        yosyscommands.push_back(yosysCommand8);
        yosyscommands.push_back(yosysCommand9);
        
        string output = executeYosysCommands(yosyscommands);
       

        // Print the output from Yosys
        cout << "Yosys Output:\n" << output << endl;
        //cout << "Yosys Output:\n" << output9 << std::endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

