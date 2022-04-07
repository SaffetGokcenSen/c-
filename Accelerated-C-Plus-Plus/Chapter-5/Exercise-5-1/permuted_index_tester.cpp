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
         << " pressing enter. Finish your input with end of file character, "
         << "Ctrl+d in linux." << endl;
    
    list<string> input_lines;
    read_lines(cin, input_lines);

    cout << endl << endl << "The lines read by the program are as follows:" << endl;

    for (list<string>::const_iterator it = input_lines.begin(); it != input_lines.end(); ++it) {
        cout << *it << endl; 
    }

    list<Line_rotations> rotated_lines;
    rotate_lines(input_lines, rotated_lines);

    cout << endl << "The first and last words of the lines and their rotations are as follows:" << endl;
    list<string> the_rotated_line;
    list<string>::const_iterator it2;
    for (list<Line_rotations>::const_iterator it = rotated_lines.begin(); it != rotated_lines.end(); ++it) {
        cout << it->firstWord << " " << it->lastWord << endl;
        the_rotated_line = it->rotation;
        for (it2 = the_rotated_line.begin(); it2 != the_rotated_line.end(); ++it2) {
            cout << *it2 << " ";
        }
        cout << endl;
    }

    rotated_lines.sort(string_compare);

    cout << endl << "The rotated lines are listed in alphabetical order as follows:" << endl;
    for (list<Line_rotations>::const_iterator it = rotated_lines.begin(); it != rotated_lines.end(); ++it) {
        the_rotated_line = it->rotation;
        for (it2 = the_rotated_line.begin(); it2 != the_rotated_line.end(); ++it2) {
            cout << *it2 << " ";
        }
        cout << endl;
    }

    list<string::size_type> char_num_list;

    char_num_list = num_of_unrotation_chars(rotated_lines);

    cout << endl << "The number of characters needed to unrotate the lines are as follows:" << endl;
    for (list<string::size_type>::const_iterator it = char_num_list.begin(); it != char_num_list.end(); ++it) {
        cout << *it << endl;
    }

    list<string> the_permuted_index;
    the_permuted_index = permuted_index(char_num_list, rotated_lines);

    return 0;
}