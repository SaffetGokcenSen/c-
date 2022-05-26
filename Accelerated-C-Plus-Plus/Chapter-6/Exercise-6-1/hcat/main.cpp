#include "Hcat.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    // the first group of strings
    string string11 = "There is a lot of sugar in the tea";
    string string12 = "The mountains are drained by streams teeming with fish";
    string string13 = "It is a great mountain";
    string string14 = "we do not need a computer failure to contend with as "
                      "well as our all other problems";

    // the left and the right vectors of strings
    vector<string> vector1, vector2;

    // the elements of the first vector are stored
    vector1.push_back(string11);
    vector1.push_back(string12);
    vector1.push_back(string13);

    // the second group of strings
    string string21 = "there are numerous dairy farms in this district";
    string string22 = "let us investigate the status of the document";

    // the elements of the second string are stored
    vector2.push_back(string21);
    vector2.push_back(string22);

    cout << "The first vector of strings is as follows:" << endl << endl;
    for (vector<string>::size_type i = 0; i != vector1.size(); ++i) {
        cout << vector1[i] << endl;
    }

    cout << endl << "The second vector of strings is as follows:" << endl << endl;
    for (vector<string>::size_type i = 0; i != vector2.size(); ++i) {
        cout << vector2[i] << endl;
    }

    cout << endl << "The horizontally concatenated string with the first one on "
         << "the left is as follows:" << endl << endl;
    vector<string> hcat_vector1 = hcat(vector1, vector2);
    for (vector<string>::size_type i = 0; i != hcat_vector1.size(); ++i) {
        cout << hcat_vector1[i] << endl;
    }

    cout << endl << "The horizontally concatenated string with the first one on "
         << "the right is as follows:" << endl << endl;
    vector<string> hcat_vector2 = hcat(vector2, vector1);
    for (vector<string>::size_type i = 0; i != hcat_vector2.size(); ++i) {
        cout << hcat_vector2[i] << endl;
    }

    return 0;
}