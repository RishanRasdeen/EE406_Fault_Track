#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// #include <cstdlib>
//  #include <set>

using namespace std;

vector<int> ReadUniqueIntegersFromFile(const string &filename)
{
    vector<int> intVector;

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Failed to open the file." << endl;
        return intVector; // Return an empty vector in case of an error
    }

    string line;

    while (getline(inputFile, line))
    {
        int value = atoi(line.c_str());
        intVector.push_back(value);
    }

    inputFile.close();

    return intVector;
}

// int main()
// {
//     string filename = "exfaultnodes.txt"; // Replace with the path to your text file
//     vector<int> uniqueIntegers = ReadUniqueIntegersFromFile(filename);

//     // Use a set to remove duplicates
//     set<int> uniqueInts(uniqueIntegers.begin(), uniqueIntegers.end());

//     vector<int> uniqueIntVector(uniqueInts.begin(), uniqueInts.end());

//     if (!uniqueIntVector.empty())
//     {
//         cout << "Unique Integers from the file:" << endl;
//         for (int value : uniqueIntVector)
//         {
//             cout << value << endl;
//         }
//     }

//     return 0;
// }
