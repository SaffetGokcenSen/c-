#include <string>
#include <map>
#include <iostream>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string s;
    map<string, int> counters; // store each word and an associated counter

    cout << "Please enter a word on each line and quit your input with the "
         << "end-of-file character which is ctrl+d in linux." << endl;
    // read the input, keeping track of each word and how often we see it
    while (cin >> s) ++counters[s];

    cout << endl << "The number of occurrences of each entered word are as "
         << "follows:" << endl;
    // write the words and associated counts
    for (map<string, int>::const_iterator it = counters.begin(); 
    it != counters.end(); ++it) {
        cout << it->first << "\t" << it->second << endl; 
    }
    return 0;
}