#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void divideAndWriteToFile(const vector<string> &inputVector, int elementsPerLine, const string &outputFile)
{
    if (elementsPerLine <= 0)
    {
        cout << "Invalid number of elements per line. Must be greater than 0." << endl;
        return;
    }

    ofstream outFile(outputFile);

    if (!outFile.is_open())
    {
        cerr << "Failed to open the output file." << endl;
        return;
    }

    for (int i = 0; i < inputVector.size(); i++)
    {
        outFile << inputVector[i];

        if ((i + 1) % elementsPerLine == 0 || i == inputVector.size() - 1)
        {
            outFile << endl;
        }
    }

    outFile.close();
}