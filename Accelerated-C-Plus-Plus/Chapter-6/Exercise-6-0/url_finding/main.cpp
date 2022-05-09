#include "Urls.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::string;
using std::vector;

int main() {
    cout << "Please enter some strings separated by newlines. The program will "
         << "extract the urls from these strings. Quit your input using the "
         << "end-of-file character which is ctrl+d in linux." << endl;
    
    string the_string;
    vector<string> string_vector;
    while(getline(cin, the_string)) {
        string_vector.push_back(the_string);
    }
    
    cout << endl;
    typedef vector<string>::const_iterator iter;
    for (iter it = string_vector.begin(); 
    it != string_vector.end(); ++it) {
        vector<string> url_vector;
        string current_string = *it;
        url_vector = find_urls(current_string);
        cout << endl;
        if (url_vector.size() != 0) {
            cout << "The urls in the string" << endl << current_string << endl
                 << "are as follows:" << endl;
            for (iter url_it = url_vector.begin(); url_it != url_vector.end(); 
            ++url_it) {
                cout << *url_it << endl;
            }
        }
        else {
            cout << "There are no urls in the string" << endl << current_string
                 << endl;
        }
    }

    return 0;
}