#include "Reversible_access.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    cout << "Please enter some integers separated by newlines. Please quit your "
         << "input with the"
         << endl
         << "end-of-file character which is ctrl+d in linux." << endl;

    int the_integer;
    vector<int> integer_vector;
    while (cin >> the_integer) {
        integer_vector.push_back(the_integer);
    }

    ::reverse(integer_vector.begin(), integer_vector.end());

    cout << "The integers you entered are listed in reverse order as follows:"
         << endl;
    
    for (vector<int>::const_iterator it = integer_vector.begin(); 
    it != integer_vector.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}