#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

struct Gate
{
    std::string type;
    std::string input1;
    std::string input2;
    std::string output;
};

struct Module
{
    std::string name;
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;
    std::vector<std::string> wires;
};

int main()
{
    std::ifstream inputFile("MUX32_Syn.v");
    std::ofstream outputFile("mux32faultnodes.txt");
    // Check if the file is open
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create the output file." << std::endl;
        return 1;
    }

    std::string line;
    std::vector<Gate> gates;
    Gate currentGate;
    Module currentModule;
    bool inModule = false;

    // Define counters for elements
    int gateNumber = 1;
    int signalNumber = 1;
    // int wireNumber = 1;

    // Maps to store element names and their corresponding numbers
    std::map<std::string, int> gateNumbers;
    std::map<std::string, int> signalNumbers;
    // std::map<std::string, int> wireNumbers;

    while (std::getline(inputFile, line))
    {
        // Skip lines starting with "(* src = "
        if (line.find("(* src = ") != std::string::npos)
        {
            continue;
        }

        // Check if this line defines a gate instance
        if (line.find("NOT") != std::string::npos || line.find("OR") != std::string::npos ||
            line.find("NAND") != std::string::npos || line.find("AND") != std::string::npos || line.find("NOR") != std::string::npos || line.find("XOR") != std::string::npos || line.find("BUF") != std::string::npos)
        {
            if (line.find("NOT") != std::string::npos)
            {
                currentGate.type = "NOT";
            }
            else if (line.find("BUF") != std::string::npos)
            {
                currentGate.type = "BUF";
            }
            else if (line.find("OR") != std::string::npos)
            {
                currentGate.type = "OR";
            }
            else if (line.find("NAND") != std::string::npos)
            {
                currentGate.type = "NAND";
            }
            else if (line.find("NOR") != std::string::npos)
            {
                currentGate.type = "NOR";
            }
            else if (line.find("XOR") != std::string::npos)
            {
                currentGate.type = "XOR";
            }
            else if (line.find("AND") != std::string::npos)
            {
                currentGate.type = "AND";
            }
            if (inModule)
            {
                if (signalNumbers.find(currentGate.input1) != signalNumbers.end())
                {
                    currentGate.input1 = "Signal" + std::to_string(signalNumbers[currentGate.input1]);
                }
                if (signalNumbers.find(currentGate.input2) != signalNumbers.end())
                {
                    currentGate.input2 = "Signal" + std::to_string(signalNumbers[currentGate.input2]);
                }
                if (signalNumbers.find(currentGate.output) != signalNumbers.end())
                {
                    currentGate.output = "Signal" + std::to_string(signalNumbers[currentGate.output]);
                }
                gateNumbers[currentGate.output] = gateNumber++;
            }
        }
        else if (line.find(".A(") != std::string::npos)
        {
            std::istringstream iss(line);
            iss.ignore(256, '.');
            iss.ignore(256, 'A');
            iss.ignore(256, '(');
            std::string input1WithSpace;
            std::getline(iss, input1WithSpace, ')');
            // std::getline(iss, currentGate.input1, ')');
            size_t lastNonSpace = input1WithSpace.find_last_not_of(" \t");
            if (lastNonSpace != std::string::npos)
            {
                currentGate.input1 = input1WithSpace.substr(0, lastNonSpace + 1);
            }
            else
            {
                currentGate.input1 = input1WithSpace; // No trailing spaces found
            }
            if (inModule)
            {
                if (signalNumbers.find(currentGate.input1) != signalNumbers.end())
                {
                    currentGate.input1 = std::to_string(signalNumbers[currentGate.input1]);
                }
                // signalNumbers[currentGate.input1] = signalNumber++;
            }
        }
        else if (line.find(".B(") != std::string::npos)
        {
            std::istringstream iss(line);
            iss.ignore(256, '.');
            iss.ignore(256, 'B');
            iss.ignore(256, '(');
            std::string input2WithSpace;
            std::getline(iss, input2WithSpace, ')');
            // std::getline(iss, currentGate.input1, ')');
            size_t lastNonSpace = input2WithSpace.find_last_not_of(" \t");
            if (lastNonSpace != std::string::npos)
            {
                currentGate.input2 = input2WithSpace.substr(0, lastNonSpace + 1);
            }
            else
            {
                currentGate.input2 = input2WithSpace; // No trailing spaces found
            }
            // std::getline(iss, currentGate.input2, ')');
            if (inModule)
            {
                if (signalNumbers.find(currentGate.input2) != signalNumbers.end())
                {
                    currentGate.input2 = std::to_string(signalNumbers[currentGate.input2]);
                }
                // signalNumbers[currentGate.input2] = signalNumber++;
            }
        }
        else if (line.find(".Y(") != std::string::npos)
        {
            std::istringstream iss(line);
            iss.ignore(256, '.');
            iss.ignore(256, 'Y');
            iss.ignore(256, '(');
            std::string outputWithSpace;
            std::getline(iss, outputWithSpace, ')');
            // std::getline(iss, currentGate.input1, ')');
            size_t lastNonSpace = outputWithSpace.find_last_not_of(" \t");
            if (lastNonSpace != std::string::npos)
            {
                currentGate.output = outputWithSpace.substr(0, lastNonSpace + 1);
            }
            else
            {
                currentGate.output = outputWithSpace; // No trailing spaces found
            }
            // std::getline(iss, currentGate.output, ')');
            if (inModule)
            {
                if (signalNumbers.find(currentGate.output) != signalNumbers.end())
                {
                    currentGate.output = std::to_string(signalNumbers[currentGate.output]);
                }
                gateNumbers[currentGate.output] = gateNumber++;
            }
            gates.push_back(currentGate);
            currentGate = {};
        }
        else if (line.find("module ") != std::string::npos)
        {
            // Entering a new module
            inModule = true;
            currentModule.name = line.substr(line.find("module ") + 7, line.find("(") - line.find("module ") - 7);
        }
        else if (line.find("input ") != std::string::npos && inModule)
        {
            std::string inputName = line.substr(line.find("input ") + 6, line.find(";") - line.find("input ") - 6);

            size_t lastNonSpace = inputName.find_last_not_of(" \t");
            if (lastNonSpace != std::string::npos)
            {
                inputName = inputName.substr(0, lastNonSpace + 1);
            }

            currentModule.inputs.push_back(inputName);
            if (signalNumbers.find(inputName) != signalNumbers.end())
            {
                inputName = std::to_string(signalNumbers[inputName]);
            }
            signalNumbers[inputName] = signalNumber++;
        }
        else if (line.find("output ") != std::string::npos && inModule)
        {
            std::string outputName = line.substr(line.find("output ") + 7, line.find(";") - line.find("output ") - 7);

            size_t lastNonSpace = outputName.find_last_not_of(" \t");
            if (lastNonSpace != std::string::npos)
            {
                outputName = outputName.substr(0, lastNonSpace + 1);
            }

            currentModule.outputs.push_back(outputName);
            if (signalNumbers.find(outputName) != signalNumbers.end())
            {
                outputName = std::to_string(signalNumbers[outputName]);
            }
            signalNumbers[outputName] = signalNumber++;
        }
        else if (line.find("wire ") != std::string::npos && inModule)
        {
            std::string wireName = line.substr(line.find("wire ") + 5, line.find(";") - line.find("wire ") - 5);

            size_t lastNonSpace = wireName.find_last_not_of(" \t");
            if (lastNonSpace != std::string::npos)
            {
                wireName = wireName.substr(0, lastNonSpace + 1);
            }

            currentModule.wires.push_back(wireName);
            signalNumbers[wireName] = signalNumber++;
        }
    }

    // Closing the input file
    inputFile.close();

    // Print extracted module information with numbers
    std::cout << "Modules: " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Module Name: " << currentModule.name << std::endl;
    std::cout << "Inputs: ";
    for (const auto &input : currentModule.inputs)
    {
        std::cout << input << "(" << signalNumbers[input] << ") ";
    }
    std::cout << std::endl;

    std::cout << "Outputs: ";
    for (const auto &output : currentModule.outputs)
    {
        std::cout << output << "(" << signalNumbers[output] << ") ";
    }
    std::cout << std::endl;

    std::cout << "Wires: ";
    for (const auto &wire : currentModule.wires)
    {
        std::cout << wire << "(" << signalNumbers[wire] << ") ";
    }
    std::cout << std::endl;

    std::cout << "--------------------------------------------" << std::endl;

    // Print extracted gate information with numbers
    std::cout << "Gate Information: " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    for (const auto &gate : gates)
    {
        std::cout << "Gate Type: " << gate.type << std::endl;
        if (!gate.input2.empty())
        {
            std::cout << "Input 1: " << gate.input1 << " ";
            outputFile << gate.input1 << std::endl;
            std::cout << "Input 2: " << gate.input2 << " ";
            outputFile << gate.input2 << std::endl;
        }
        else
        {
            std::cout << "Input: " << gate.input1 << " ";
            outputFile << gate.input1 << std::endl;
        }
        std::cout << "Output: " << gate.output << " " << std::endl;
        outputFile << gate.output << std::endl;
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    outputFile.close();
    return 0;
}
