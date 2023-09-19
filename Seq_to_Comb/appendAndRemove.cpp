#include <iostream>
#include <vector>
#include <algorithm>

// Function to append unique items from vector2 to vector1
void appendAndRemoveDuplicates(std::vector<std::string> &vector1, const std::vector<std::string> &vector2)
{
    // Concatenate vector2 with vector1
    vector1.insert(vector1.end(), vector2.begin(), vector2.end());

    // Sort the combined vector
    std::sort(vector1.begin(), vector1.end());

    // Use std::unique to remove duplicate terms
    auto uniqueEnd = std::unique(vector1.begin(), vector1.end());

    // Resize vector1 to remove the duplicates
    vector1.resize(std::distance(vector1.begin(), uniqueEnd));
}