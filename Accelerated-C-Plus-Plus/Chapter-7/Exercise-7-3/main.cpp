#include "Cross_reference.h"

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::cin;
using std::map;

int main() {
    cout << "Please enter lines separated by newlines. Please quit your input "
         << "with the end of file character which is ctrl+d in linux." << endl;
    
    // the lines are read in
    list<string> line_list = read_lines(cin);

    // the cross reference is created
    map<string, list<int> > xref = create_xref(line_list);

    // a newline is printed for clear output
    cout << endl;

    // the cross reference is written down
    for (map<string, list<int> >::const_iterator it = xref.begin(); 
    it != xref.end(); ++it) {
        cout << "The word '" << it->first << "' occurs in the lines with the "
             << "following numbers:" << endl;
        list<int> line_num_list = it->second;
        list<int>::const_iterator it2 = line_num_list.begin();
        // if there is only one line number, write it down. Otherwise, write the
        // first number, then append a blank and another number till the end of 
        // the list.
        if (line_num_list.size() == 1) {
            cout << *it2;
        }
        else {
            cout << *it2;
            ++it2;
            while (it2 != line_num_list.end()) {
                cout << " " << *it2;
                ++it2;
            }
        }
        cout << endl;
    }

    return 0;
}