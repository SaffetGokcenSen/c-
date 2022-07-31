#include "Sequential_write_only_access.h"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::list;
using std::cin;
using std::vector;
using std::back_inserter;

int main() {
    cout << "Please enter some integers separated by newlines. Please quit your"
         << " input with the" << endl
         << "end-of-file character which is ctrl+d in linux." << endl;
    
    // the list into which the entered integers are to be stored
    list<int> integer_list;
    int the_integer;
    // the input integers are stored in the list
    while (cin >> the_integer) {
        integer_list.push_back(the_integer);
    }

    vector<int> integer_vector;
    ::copy(integer_list.begin(), integer_list.end(), back_inserter(integer_vector));

    cout << "The integers entered by the user are as follows:" << endl;
    
    for (vector<int>::const_iterator it = integer_vector.begin(); 
    it != integer_vector.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}