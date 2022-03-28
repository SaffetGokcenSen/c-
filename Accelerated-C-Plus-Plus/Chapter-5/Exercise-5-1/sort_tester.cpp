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

    cout << endl << endl << "The lines read by the program are as follows:" << endl;

    for (list<string>::const_iterator it = input_lines.begin(); it != input_lines.end(); ++it) {
        cout << *it << endl; 
    }

    list<Line_rotations> rotated_lines;
    rotate_lines(input_lines, rotated_lines);

    cout << endl << "The first words of the lines and their rotations are as follows:" << endl;
    list<string> the_rotated_lines;
    for (list<Line_rotations>::const_iterator it = rotated_lines.begin(); it != rotated_lines.end(); ++it) {
        cout << it->firstWord << endl;
        cout << it->rotation << endl;
        cout << "------------------------------" << endl;
    }

    rotated_lines.sort(string_compare);

    cout << endl << "The first words of the lines and their rotations in alphabetical order are as follows:" << endl;
    for (list<Line_rotations>::const_iterator it = rotated_lines.begin(); it != rotated_lines.end(); ++it) {
        cout << it->firstWord << endl;
        cout << it->rotation << endl;
        cout << "------------------------------" << endl;
    }

    return 0;
}