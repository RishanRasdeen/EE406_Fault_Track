#include <iostream>
#include <vector>
#include <random>

using namespace std;

random_device rd;
mt19937 generator(rd());

int random(vector<int> const &numbers)
{

    uniform_int_distribution<int> dis(0, numbers.size());
    int r = dis(generator);
    return numbers[r];
}

// int main()
// {

//     cout << rand();
//     return 0;
// }