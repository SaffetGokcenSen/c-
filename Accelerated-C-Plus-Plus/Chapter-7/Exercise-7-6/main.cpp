#include "Grammar.h"

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::list;

int main() {
    try {
        // the grammar is read in
        Grammar the_grammar = read_grammar(cin);
        
        cout << "Please enter a category to sample from. The category must be an" 
             << " existing one and embedded in '<' and '>'." << endl;
        string the_category;
        cin >> the_category;

        list<string> the_sample = generate_category(the_grammar, the_category);
        cout << "The sample from the requested category is as follows:" << endl;
        list<string>::const_iterator it = the_sample.begin();
        cout << *it;
        ++it;
        while (it != the_sample.end()) {
            cout << " " << *it;
            ++it;
        }
        cout << endl;

        return 0;
    }
    catch (string first_word) {
        cout << endl << "There is a problem in the input. The first word of each" 
             << endl
             << "of the grammar lines must be a category which is a word embedded"
             << endl
             << "in '<' and '>'. However, the first word of the last line is '" 
             << first_word << "'." << endl;
        return 1;
    }
}