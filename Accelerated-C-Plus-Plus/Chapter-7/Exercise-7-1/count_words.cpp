#include "Count_words.h"

using std::map;
using std::string;
using std::istream;

// the predicate used to sort the elements of a list of pairs
bool sort_predicate(const int& a, const int& b) {
    return a < b;
}

// counts the words coming from the input stream
map<string, int> count_words(istream& in) {
    map<string, int> word_to_count;
    string the_word;
    while(in >> the_word) {
        ++word_to_count[the_word];
    }

    return word_to_count;
}