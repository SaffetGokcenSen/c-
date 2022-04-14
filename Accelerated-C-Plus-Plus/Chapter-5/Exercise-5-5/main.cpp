#include "Process_picture.h"
#include <string>
#include <list>
#include <iostream>

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    list<string> the_picture, centered_picture;

    read_lines(cin, the_picture);

    centered_picture = center_picture(the_picture);

    list<string>::const_iterator it;
    string asterisks(80, '*');
    cout << asterisks << endl;
    for (it = the_picture.begin(); it != the_picture.end(); ++it) {
        cout << *it << endl;
    }
    cout << asterisks << endl;
    
    cout << asterisks << endl;
    for (it = centered_picture.begin(); it != centered_picture.end(); ++it) {
        cout << *it << endl;
    }
    cout << asterisks << endl;

    return 0;
}