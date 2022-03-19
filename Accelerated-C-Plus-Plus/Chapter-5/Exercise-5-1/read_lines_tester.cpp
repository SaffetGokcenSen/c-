#include "Process_lines.h"
#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::cin;

int main() {
    cout << "Please enter lines separated by newlines that can be created by"
         << " pressing enter." << endl;
    
    list<string> input_lines;
    read_lines(cin, input_lines);

    cout << endl << "The lines read by the program are as follows:" << endl;

    for (list<string>::const_iterator it = input_lines.begin(); it != input_lines.end(); ++it) {
        cout << *it << endl; 
    }

    return 0;
}
