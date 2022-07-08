#include "Sentence_generation.h"

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::string;
using std::list;

int main() {
    try {
        // the grammar is read in
        Grammar the_grammar = read_grammar(cin);
        cout << endl << endl << "The categories of the grammar are written as " 
         << "follows:" << endl;
         
         // the Grammar is written
         for (Grammar::const_iterator it = the_grammar.begin(); 
         it != the_grammar.end(); ++it) {
            cout << endl << it->first << ":" << endl;
            for (vector<Rule>::const_iterator it2 = it->second.begin(); 
            it2 != it->second.end(); ++it2) {
                Rule the_rule = *it2;
                for (Rule::const_iterator it3 = the_rule.begin();
                it3 != the_rule.end(); ++it3) {
                    cout << *it3 << " ";
                }
                cout << endl;
            }
        }

        cout << endl;

        cout << "Please enter the category you want a sample from. Please do not"
        << " embed the category name in '<' and '>'." << endl;
        string category_name;
        cin >> category_name;
        category_name = '<' + category_name + '>'; 

        list<string> category_sample;
        sample_category(the_grammar, category_name, category_sample);

        cout << "The sample from the requested category is as follows:" << endl;
        list<string>::const_iterator it = category_sample.begin();
        cout << *it;
        ++it;
        while (it != category_sample.end()) {
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