#include <iostream>
#include <vector>
#include <algorithm>

// Function to remove common terms from vector1
void removeCommonTerms(std::vector<std::string> &vector1, const std::vector<std::string> &vector2)
{
    // Create a new vector to store the unique terms
    std::vector<std::string> uniqueTerms;

    // Iterate through vector1 and check if each term is in vector2
    for (const std::string &term : vector1)
    {
        if (std::find(vector2.begin(), vector2.end(), term) == vector2.end())
        {
            uniqueTerms.push_back(term);
        }
    }

    // Update vector1 with the unique terms
    vector1 = uniqueTerms;
}
