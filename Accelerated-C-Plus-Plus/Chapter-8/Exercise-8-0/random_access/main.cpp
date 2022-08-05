#include "Random_access.h"
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::sort;

int main() {
    cout << "Please enter some integers separated by newlines. Please quit your "
         << "input with the end-of-file character." << endl;

    int the_integer;
    vector<int> integer_vector;
    while (cin >> the_integer)
    {
        integer_vector.push_back(the_integer);
    }

    // the integer vector must be sorted before applying the binary search
    sort(integer_vector.begin(), integer_vector.end());
    
    // the integer 6 is searched in the sorted vector of integers
    bool six_exists = 
    ::binary_search(integer_vector.begin(), integer_vector.end(), 6);

    if (six_exists) {
        cout << "The integer 6 exists in the input." << endl;
    }
    else {
        cout << "The integer 6 does not exist in the input." << endl;
    }

    return 0;

}