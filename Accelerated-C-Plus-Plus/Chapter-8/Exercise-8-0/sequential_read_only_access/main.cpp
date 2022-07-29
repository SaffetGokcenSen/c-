#include "Sequential_read_only_access.h"
#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::list;

int main() {
    cout << "You will enter some integers separated by newlines. Before starting "
         << "your input, " << endl
         << "you should determine where these integers are to be stored. These "
         << "integers will " << endl
         << "be stored in either a vector or a list. Please indicate your "
         << "storage choice with" << endl
         <<"'l' for list and with 'v' for vector." << endl;
    
    int the_integer;
    char choice;
    while (cin >> choice) {
        if (choice == 'l') {
            cout << "Please start entering integers separated by newlines. "
                 << "Please quit your input with" << endl
                 << "the end-of-file character which is ctrl+d in linux." 
                 << endl;
            list<int> integer_list;
            while (cin >> the_integer) {
                integer_list.push_back(the_integer);
            }
            list<int>::const_iterator it = find(integer_list.begin(), 
            integer_list.end(), 1);
            if (it == integer_list.end()) {
                cout << "1 does not exist among the integers you entered." << endl;
            }
            else {
                cout << "1 exists among the integers you entered." << endl;
            }
        }
        else if (choice == 'v') {
            cout << "Please start entering integers separated by newlines. "
                 << "Please quit your input with" << endl
                 << "the end-of-file character which is ctrl+d in linux." 
                 << endl;
            vector<int> integer_vector;
            while (cin >> the_integer) {
                integer_vector.push_back(the_integer);
            }
            vector<int>::const_iterator it = find(integer_vector.begin(), 
            integer_vector.end(), 1);
            if (it == integer_vector.end()) {
                cout << "1 does not exist among the integers you entered." << endl;
            }
            else {
                cout << "1 exists among the integers you entered." << endl;
            }
        }
    }

    return 0;
}