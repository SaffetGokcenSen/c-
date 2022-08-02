#include "Sequential_read_write_access.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    cout << "Please enter either of 'a', 'b' and 'c' at random separated by "
         <<"newlines. Please"
         << endl
         << "quit your input with the end-of-file character which is ctrl+d in " 
         << "linux." << endl;
    
    vector<char> letter_vector;
    char the_letter;
    while (cin >> the_letter) {
        letter_vector.push_back(the_letter);
    }

    replace(letter_vector.begin(), letter_vector.end(), 'a', 'z');
    replace(letter_vector.begin(), letter_vector.end(), 'b', 'y');
    replace(letter_vector.begin(), letter_vector.end(), 'c', 'x');

    cout << "Here are the letters you entered with 'a' replaced with 'z', 'b' "
         << "replaced with"
         << endl
         << "'y' and 'c' replaced with 'z'." << endl;
    
    for (vector<char>::const_iterator it = letter_vector.begin(); 
    it != letter_vector.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}