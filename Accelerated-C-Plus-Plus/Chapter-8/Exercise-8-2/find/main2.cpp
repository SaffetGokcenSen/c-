#include "Find.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    cout << "Please enter a sequence of characters separated by blanks. Please "
         << "quit your input"
         << endl
         << "with end-of-file character which is ctrl+d in linux." << endl;
    
    char the_char;
    vector<char> char_vector;
    while (cin >> the_char) {
        char_vector.push_back(the_char);
    }

    cout << endl;

    vector<char>::const_iterator it = ::find(char_vector.begin(), char_vector.end(), 'z');

    if (it == char_vector.end()) {
        cout << "z does not exist in the sequence you entered." << endl;
    }
    else {
        cout << "z exists in the sequence you entered." << endl;
    }

    return 0;
}