// C++ program for the above approach
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Function to find the key values
// according to given mapped value K
void printKey(map<string, int> &inputMap, map<string, int> &wireMap, map<string, int> &outputMap, vector<int> &K, vector<string> &faultnames)
{

    // If a is true, then we have
    // not key-value mapped to K
    bool a = true;

    // Traverse the map
    for (auto &it : inputMap)
    {

        // If mapped value is K,
        // then print the key value
        for (auto &it2 : K)
        {
            if (it.second == it2)
            {
                // cout << it.first << ' ';
                faultnames.push_back(it.first);
                a = false;
            }
        }
    }

    for (auto &it : wireMap)
    {

        // If mapped value is K,
        // then print the key value
        for (auto &it2 : K)
        {
            if (it.second == it2)
            {
                // cout << it.first << ' ';
                faultnames.push_back(it.first);
                a = false;
            }
        }
    }

    for (auto &it : outputMap)
    {

        // If mapped value is K,
        // then print the key value
        for (auto &it2 : K)
        {
            if (it.second == it2)
            {
                // cout << it.first << ' ';
                faultnames.push_back(it.first);
                a = false;
            }
        }
    }

    // If there is not key mapped with K,
    // then print -1
    if (a)
    {
        cout << "-1";
    }
}

// Driver Code
// int main()
// {
//     map<string, int> Map;

//     // Given map
//     Map["1"] = 3;
//     Map["2"] = 3;
//     Map["4"] = -1;
//     Map["7"] = 2;
//     Map["10"] = 3;

//     // Given value K
//     int K = 3;

//     // Function call
//     printKey(Map, K);
//     return 0;
// }
