#include "Find_if.h"
#include <iostream>
#include <cctype>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::isupper;

bool IsEven (int i) {
  return ((i % 2) == 0);
}

int main() {
    cout << "Please enter some integers separated by blanks. Please quit your "
         << "input with the" << endl
         << "character which is ctrl+d in linux." << endl;
    
    int the_int;
    vector<int> int_vector;
    while(cin >> the_int) {
        int_vector.push_back(the_int);
    }

    cout << endl;
    
    vector<int>::const_iterator b = int_vector.begin();
    vector<int>::const_iterator e = int_vector.end();
    if (e != ::find_if(b, e, IsEven)) {
        cout << "There is an even integer in your input." << endl;
    }
    else {
        cout << "There is not an even integer in your input." << endl;
    }

    return 0;
}