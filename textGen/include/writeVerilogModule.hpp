#include <vector>
#include <string>

using namespace std;

void writeVerilogModule(const string &moduleName, const vector<string> &inputs, const vector<string> &outputs, const vector<string> &wires, ofstream &outputFile);