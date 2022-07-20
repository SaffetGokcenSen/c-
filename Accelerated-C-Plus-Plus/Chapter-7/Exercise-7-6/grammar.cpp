#include "Grammar.h"
#include <chrono>
#include <random>
#include <algorithm>

using std::list;
using std::string;
using std::cout;
using std::endl;
using std::uniform_int_distribution;
using std::default_random_engine;
using std::chrono::system_clock;
using std::vector;
using std::find_if;

// split the line into its words
list<string> extract_words(const string& line) {
    list<string> words_list;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != line.size()) {
        while (i != line.size() && isspace(line[i])) {
            ++i;
        }
        
        string_size j = i;
        while (j != line.size() && !isspace(line[j])){
            ++j;
        }

        if (i != j) {
            words_list.push_back(line.substr(i, j - i));
            i = j;          
        }
    }

    return words_list;
}

// read the grammar from the input stream
Grammar read_grammar(std::istream& in) {
    // the grammar read from the input stream
    Grammar the_grammar;
    // prompt the user for entering the grammar
    cout << "Please enter the grammar line by line. Please quit your input with "
         << "the '|' character." << endl;
    
    string line;
    while (getline(in, line)) {
        // words of the line
        list<string> words = extract_words(line);
        list<string>::const_iterator it = words.begin();
        // first word of the line
        string first_word = *it;
        if (first_word[0] == '|') {
            return the_grammar;
        }
        else {
            // if the first word is a valid category, add the rest of the line 
            // to the related category of the grammar map
            if ((first_word[0] == '<') && (first_word.size() >= 3) && 
            (first_word[first_word.size() - 1] == '>')) {
                ++it;
                Rule the_rule;
                do {
                    the_rule.push_back(*it);
                    ++it;
                }
                while (it != words.end());
                the_grammar[first_word].push_back(the_rule);
            }
            else {
                throw (first_word);
            }
        }
    }
    
    return the_grammar;
}

// generate a random integer which is smaller than a given bound
int rand_int(int upper_bound) {
    // The time duration in nanoseconds that has elapsed since 00:00:00 
    // Coordinated Universal Time (UTC), Thursday, 1 January 1970, not counting 
    // leap seconds. In this 64 bit linux system, seed can have values up to 2 
    // to the power 64 minus 1.
    unsigned seed = system_clock::now().time_since_epoch().count();
    // random number generator is created using the seed
    default_random_engine generator (seed);
    // the distribution from which the random integer is to be sampled is 
    // declared.
    uniform_int_distribution<int> distribution(0,upper_bound - 1);
    
    // the random integer is sampled.
    int random_int = distribution(generator);

    return random_int;
}

// determines if a string represents a category
bool is_category(const string& the_string) {
    string::size_type the_size = the_string.size();
    if ((the_string[0] == '<') && (the_size >= 3) && 
    (the_string[the_size - 1] == '>')) {
        return true;
    }
    else {
        return false;
    }
}

// sample a category entered by the user
std::list<std::string> generate_category(Grammar& the_grammar, 
const std::string& the_category) {
    // the vector of rules corresponding to the entered category are got
    vector<Rule> rule_vector = the_grammar[the_category];
    // a rule is sampled from the vector of rules
    Rule the_rule = rule_vector[rand_int(rule_vector.size())];
    // the iterator for the rule
    list<string>::iterator it;
    // determines if the loop is to be quit
    bool quit_loop;
    do
    {
        // find the first category in the rule
        it = find_if(the_rule.begin(), the_rule.end(), is_category);
        // is there a category?
        quit_loop = it != the_rule.end();
        // if there is a category
        if (quit_loop) {
            // expand the category
            vector<Rule> rule_vector_2 = the_grammar[*it];
            // get the rule
            Rule the_rule_2 = rule_vector_2[rand_int(rule_vector_2.size())];
            // insert the rule into the original rule
            the_rule.insert(it, the_rule_2.begin(), the_rule_2.end());
            // erase the category from the original rule
            the_rule.erase(it);
        }
    } while (quit_loop);

    return the_rule;
}