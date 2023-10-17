#include <iostream>
#include <fstream>
#include <vector>

void divideAndWriteToFile(const std::vector<int> &inputVector, int elementsPerLine, const std::string &outputFile)
{
    if (elementsPerLine <= 0)
    {
        std::cout << "Invalid number of elements per line. Must be greater than 0." << std::endl;
        return;
    }

    std::ofstream outFile(outputFile);

    if (!outFile.is_open())
    {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }

    for (int i = 0; i < inputVector.size(); i++)
    {
        outFile << inputVector[i] << " ";

        if ((i + 1) % elementsPerLine == 0 || i == inputVector.size() - 1)
        {
            outFile << "\n";
        }
    }

    outFile.close();
}

int main()
{
    std::vector<int> inputVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::string outputFile = "output.txt";
    int elementsPerLine;

    std::cout << "Enter the number of elements to be written per line: ";
    std::cin >> elementsPerLine;

    divideAndWriteToFile(inputVector, elementsPerLine, outputFile);

    return 0;
}
