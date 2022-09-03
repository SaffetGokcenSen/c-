#include "Equal.h"
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::cin;
using std::back_inserter;

int main() {
    cout << "Please enter two sequences of equal length. Each sequence elements" 
         << " must be" << endl
         << "separated by blank spaces. Each sequence must be on a separate line." 
         << " Please" << endl 
         << "quit your input with the end-of-file character which is ctrl+d in linux."
         << endl;
    string sequence;
    vector<string> sequence_vector;
    while (getline(cin, sequence)) {
        sequence_vector.push_back(sequence);
    }

    string sequence_1 = sequence_vector[0];
    string sequence_2 = sequence_vector[1];

    vector<string> splitted_seq_1, splitted_seq_2;
    split(sequence_1, back_inserter(splitted_seq_1));
    split(sequence_2, back_inserter(splitted_seq_2));

    if (splitted_seq_1.size() != splitted_seq_2.size()) {
        cout << "The lengths of the sequences must be the same!" << endl;
        return 1;
    }
    else {
        if (::equal(splitted_seq_1.begin(), splitted_seq_1.end(), splitted_seq_2.begin())) {
            cout << "The two sequences are the same." << endl;
        }
        else {
            cout << "The two sequences are different!" << endl;
        }
        return 0;
    }
}