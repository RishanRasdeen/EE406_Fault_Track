#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <cstdio>
using namespace std;

void faultfile(const string &inputFileName, const string &outputFileName, vector<string> &faultnames, int value)
{

    ifstream inputfile(inputFileName);
    ofstream outputfile(outputFileName);

    bool startreading;
    // bool insideModule = false;
    vector<string> modulelines;
    // string newInput = "f";

    if (!inputfile.is_open())
    {
        cerr << "Error: Could not open the input file." << endl;
        return;
    }

    if (!outputfile.is_open())
    {
        cerr << "Error: Could not create the output file." << endl;
        return;
    }

    string line;
    while (getline(inputfile, line))
    {

        if (line.find("AND") != string::npos || line.find("OR") != string::npos ||
            line.find("NAND") != string::npos || line.find("NOR") != string::npos ||
            line.find("XOR") != string::npos || line.find("NOT") != string::npos)
        {
            startreading = true;
        }

        if (startreading)
        {
            if (value == 1)
            {
                for (const auto &i : faultnames)
                {
                    if (line.find(i) != string::npos)
                    {
                        line.replace(line.find(i), i.length(), i + " || f");
                    }
                }
            }

            else
            {

                for (const auto &i : faultnames)
                {
                    if (line.find(i) != string::npos)
                    {
                        line.replace(line.find(i), i.length(), i + " && f");
                    }
                }
            }
        }

        outputfile << line << endl;
    }

    inputfile.close();
    //
    outputfile.close();
}