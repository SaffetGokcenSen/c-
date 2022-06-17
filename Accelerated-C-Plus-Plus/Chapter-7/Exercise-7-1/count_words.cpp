#include "Count_words.h"

using std::map;
using std::string;
using std::istream;
using std::list;
using std::pair;

bool sort_predicate(const pair<string, int>& p1, const pair<string, int>& p2) {
    return p1.second < p2.second;
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

// sorts the contents of the input map and outputs a list of pairs
list<pair<string, int> > sort_word_count_pairs(const map<string, 
int>& word_count_map) {
    // contains the pairs of words and their occurrence counts
    list<pair<string, int> > pairs_list;

    // copies the pairs in the map to a list
    for (map<string, int>::const_iterator it = word_count_map.begin(); 
    it != word_count_map.end(); ++it) {
        pairs_list.push_back(*it);
    }

    // sort the list of pairs according to the number of occurrences
    pairs_list.sort(sort_predicate);

    return pairs_list;
}