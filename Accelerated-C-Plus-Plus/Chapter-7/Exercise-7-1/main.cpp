#include "Count_words.h"

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::cin;
using std::list;
using std::pair;

int main() {
    cout << "Please enter single words separated by newlines. Quit your input "
         << "with the end-of-file character which is ctrl+d in linux." << endl;

    map<string, int> strings_to_counts;
    strings_to_counts = count_words(cin);

    cout << endl << endl << "The entered words along with their occurrence "
         << "counts are as follows:" << endl;
    for (map<string, int>::const_iterator it = strings_to_counts.begin(); 
    it != strings_to_counts.end(); ++it) {
        cout << it->first << " occurs " << it->second << " times." << endl;
    }

    // contains the list of word-occurrence count pairs
    list<pair<string, int> > word_count_pair_list;
    word_count_pair_list= sort_word_count_pairs(strings_to_counts);

    cout << endl << "The entered words and their occurrence counts are listed "
         <<"in the ascending order as follows:" << endl;
    for (list<pair<string, int> >::const_iterator 
    it = word_count_pair_list.begin(); it != word_count_pair_list.end(); ++it) {
        cout << it->first << " occurs " << it->second << " times." << endl;
    }

    return 0;
}