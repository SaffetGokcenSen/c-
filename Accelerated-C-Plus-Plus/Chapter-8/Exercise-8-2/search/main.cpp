#include "Search.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::cin;
using std::vector;
using std::back_inserter;

int main() {
    cout << "In the first line of your input, please enter a sequence of "
         << "characters separated" << endl
         << "by blank spaces. In the second line of your input, please enter a "
         << "sequence of " << endl
         << "characters shorter than the first sequence. After entering the "
         << "second sequence, " << endl
         << "please quit your input with the end-of-file character which is "
         << "ctrl+d in linux." << endl;

    string sequence;
    vector<string> sequence_vector;
    while (getline(cin, sequence)) {
        sequence_vector.push_back(sequence);
    }

    string string_1 = sequence_vector[0];
    string string_2 = sequence_vector[1];

    vector<string> sequence_1, sequence_2;

    split(string_1, back_inserter(sequence_1));
    split(string_2, back_inserter(sequence_2));

    cout << "The elements of the first sequence are as follows:" << endl;
    for (vector<string>::const_iterator it = sequence_1.begin(); 
    it != sequence_1.end(); ++it) {
        cout << *it << endl;
    }

    cout << "The elements of the second sequence are as follows:" << endl;
    for (vector<string>::const_iterator it = sequence_2.begin(); 
    it != sequence_2.end(); ++it) {
        cout << *it << endl;
    }

    vector<string>::const_iterator b, e, b2, e2, it;
    b = sequence_1.begin();
    e = sequence_1.end();
    b2 = sequence_2.begin();
    e2 = sequence_2.end();

    it = search(b, e, b2, e2);

    if (it != e) {
        --it;
        cout << "The element before the starting point of the sequence is as "
             << "follows" << endl;
        cout << *it << endl;
    }
    else {
        cout << "The second sequence is not contained in the first sequence."
             << endl;
    }

    return 0;
}