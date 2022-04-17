#include "Frame.h"
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::getline;
using std::endl;
using std::cin;
using std::vector;

int main() {
    cout << "Please enter single words separated by newlines. Please finish "
         << "your input by the end-of-file character which is ctrl+d in linux."
         << endl;
    string the_word;
    vector<string> word_vector;
    while (getline(cin, the_word)) word_vector.push_back(the_word);

    cout << endl << endl << "The words read from the input are as follows: "
         << endl;
    for (vector<string>::size_type i = 0; i != word_vector.size(); ++i) {
        cout << word_vector[i] << endl;
    }

    vector<string> framed_words = frame(word_vector);

    cout << endl << "The words read from the input are framed as follows: "
         << endl;
    for (vector<string>::size_type i = 0; i != framed_words.size(); ++i) {
        cout << framed_words[i] << endl;
    }

    return 0;
}