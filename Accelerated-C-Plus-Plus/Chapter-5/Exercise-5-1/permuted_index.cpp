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

    list<Line_rotations> rotated_lines;
    rotate_lines(input_lines, rotated_lines);

    rotated_lines.sort(string_compare);

    list<string::size_type> char_num_list;

    char_num_list = num_of_unrotation_chars(rotated_lines);

    list<string> the_permuted_index;
    the_permuted_index = permuted_index(char_num_list, rotated_lines);

    cout << endl << endl << "The permuted index is as follows:" << endl << endl;
    for (list<string>::const_iterator it = the_permuted_index.begin(); it != the_permuted_index.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}