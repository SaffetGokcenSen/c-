#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

using std::copy;
using std::vector;
using std::copy;
using std::cout;
using std::endl;

int main() {
    //create a vector containing 10 copies of the integer 100 
    vector<int> u(10, 100);
    vector<int> v;

    // copy the contents of u to v
    copy(u.begin(), u.end(), back_inserter(v));

    cout << "The contents of u are as follows:" << endl;
    for (vector<int>::const_iterator it = u.begin(); it != u.end(); ++it) {
        cout << *it << endl;
    }

    cout << endl << "The contents of v are as follows:" << endl;
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}