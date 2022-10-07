#include "Find_if.h"
#include <iostream>
#include <cctype>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::isupper;

bool IsUpper (char c) {
  return (isupper(c));
}

int main() {
    cout << "Please enter some characters separated by blanks. Please quit your "
         << "input with the" << endl
         << "character which is ctrl+d in linux." << endl;
    
    char the_char;
    vector<char> char_vector;
    while(cin >> the_char) {
        char_vector.push_back(the_char);
    }

    cout << endl;
    
    vector<char>::const_iterator b = char_vector.begin();
    vector<char>::const_iterator e = char_vector.end();
    if (e != ::find_if(b, e, IsUpper)) {
        cout << "There is an uppercase letter in your input." << endl;
    }
    else {
        cout << "There is not an uppercase letter in your input." << endl;
    }

    return 0;
}