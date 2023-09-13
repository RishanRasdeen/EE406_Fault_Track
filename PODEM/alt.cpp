#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream inputFile("test.v"); // Replace with your Verilog file name
    ofstream outputFile("output.txt");    // Replace with your desired output file name

    map<string, string> gateTypes;
    gateTypes["AND"] = "AND";
    gateTypes["NAND"] = "NAND";
    gateTypes["OR"] = "OR";
    gateTypes["NOT"] = "NOT";
    gateTypes["input"] = "INPUT";
    gateTypes["output"] = "OUTPUT";

    map<string, string> wireMap;
    vector<string> inputs;
    vector<string> outputs;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        ss >> token;

        if (gateTypes.find(token) != gateTypes.end()) {
            if (token == "input" || token == "output") {
                while (ss >> token && token != ";") {
                    if (token != "," && token != "[" && token != "]") {
                        if (token.back() == ',' || token.back() == ';') {
                            token.pop_back();
                        }
                        if (token == "clk" || token == "rst") {
                            continue;
                        }
                        if (token == "a" || token == "b" || token == "cin") {
                            inputs.push_back(token);
                        } else if (token == "sum" || token == "cout") {
                            outputs.push_back(token);
                        }
                    }
                }
            } else {
                string gateName, outputY, inputA, inputB;
                ss >> gateName;
                ss >> outputY;
                ss >> inputA;
                ss >> inputB;

                if (!gateName.empty() && !outputY.empty() && !inputA.empty() && !inputB.empty()) {
                    wireMap[gateName] = gateTypes[token] + " " + outputY + " " + inputA + " " + inputB;
                }
            }
        }
    }

    // Write the converted format to the output file
    outputFile << "INPUT ";
    for (const string& input : inputs) {
        outputFile << input << " ";
    }
    outputFile << "-1" << endl;

    outputFile << "OUTPUT ";
    for (const string& output : outputs) {
        outputFile << output << " ";
    }
    outputFile << "-1" << endl;

    for (const auto& entry : wireMap) {
        outputFile << entry.second << " -1" << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
