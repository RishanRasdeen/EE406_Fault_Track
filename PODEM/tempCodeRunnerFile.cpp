#include <iostream>
#include <vector>
#include <algorithm>

// Function to remove common terms from vector1
void removeCommonTerms(std::vector<std::string>& vector1, const std::vector<std::string>& vector2) {
    // Sort both vectors for efficient comparison
    std::sort(vector1.begin(), vector1.end());
    std::sort(vector2.begin(), vector2.end());

    // Create a new vector to store the unique terms
    std::vector<std::string> uniqueTerms;

    // Use set_intersection to find common terms and store them in uniqueTerms
    std::set_intersection(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), std::back_inserter(uniqueTerms));

    // Erase common terms from vector1
    for (const std::string& term : uniqueTerms) {
        vector1.erase(std::remove(vector1.begin(), vector1.end(), term), vector1.end());
    }
}

int main() {
    // Create two string vectors
    std::vector<std::string> vector1 = {"apple", "banana", "cherry", "date"};
    std::vector<std::string> vector2 = {"cherry", "date", "grape"};

    // Call the function to remove common terms from vector1
    removeCommonTerms(vector1, vector2);

    // Print the modified vector1
    std::cout << "Modified vector1:" << std::endl;
    for (const std::string& term : vector1) {
        std::cout << term << " ";
    }
    std::cout << std::endl;

    return 0;
}
