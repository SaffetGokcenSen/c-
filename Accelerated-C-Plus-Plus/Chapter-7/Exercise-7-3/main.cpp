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

    // the cross reference is stated
    for (map<string, list<int> >::const_iterator it = xref.begin(); 
    it != xref.end(); ++it) {
        cout << "The word '" << it->first << "' occurs in the lines with the "
             << "following numbers:" << endl;
        list<int> line_num_list = it->second;
        for (list<int>::const_iterator it2 = line_num_list.begin(); 
        it2 != line_num_list.end(); ++it2) {
            cout << *it2;
        }
        cout << endl;
    }

    return 0;
}