#include "Find.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    cout << "Please enter a sequence of integers separated by blanks. Please "
         << "quit your input"
         << endl
         << "with end-of-file character which is ctrl+d in linux." << endl;
    
    int the_int;
    vector<int> int_vector;
    while (cin >> the_int) {
        int_vector.push_back(the_int);
    }

    cout << endl;

    vector<int>::const_iterator it = ::find(int_vector.begin(), int_vector.end(), 0);

    if (it == int_vector.end()) {
        cout << "0 does not exist in the sequence you entered." << endl;
    }
    else {
        cout << "0 exists in the sequence you entered." << endl;
    }

    return 0;
}