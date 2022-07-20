#include "Grammar.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
    cout << "Please enter a string, either embedded in '<' and '>' or not "
         << "embedded." << endl;
    
    string the_string;
    cin >> the_string;

    if (is_category(the_string)) {
        cout << "The string you entered represents a category." << endl;
    }
    else {
        cout << "The string you entered does not represent a category." << endl;
    }

    return 0;
}