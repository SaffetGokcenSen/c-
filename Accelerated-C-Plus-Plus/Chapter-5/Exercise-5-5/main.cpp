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

    cout << "Please enter the character picture. Please finish your input with "
         << "the end of file character which is ctrl+d in linux." << endl;
    read_lines(cin, the_picture);

    centered_picture = center_picture(the_picture);

    cout << endl << endl << "The picture is printed with upper and lower "
         << "asterisk lines of 80 characters:" << endl;
    list<string>::const_iterator it;
    string asterisks(80, '*');
    cout << endl << asterisks << endl;
    for (it = the_picture.begin(); it != the_picture.end(); ++it) {
        cout << *it << endl;
    }
    cout << asterisks << endl;

    cout << endl << "The centered picture is printed with upper and lower "
         << "asterisk lines of 80 characters:" << endl;
    cout << asterisks << endl;
    for (it = centered_picture.begin(); it != centered_picture.end(); ++it) {
        cout << *it << endl;
    }
    cout << asterisks << endl;

    return 0;
}