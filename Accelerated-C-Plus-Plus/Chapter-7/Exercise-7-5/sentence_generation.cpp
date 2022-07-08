#include "Sentence_generation.h"
#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::getline;
using std::string;
using std::list;
using std::endl;
using std::uniform_int_distribution;
using std::default_random_engine;
using std::chrono::system_clock;
using std::vector;

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

// generate a sample from a category entered by the user
list<string> sample_category(Grammar& the_grammar, const string& category,
list<string>& the_sample) {
    // typedef std::vector<std::string> Rule;
    // typedef std::map<std::string, std::vector<Rule> > Grammar;
    vector<Rule> rule_vector = the_grammar[category];
    Rule the_rule = rule_vector[rand_int(rule_vector.size())];
    for (Rule::const_iterator it = the_rule.begin(); it != the_rule.end(); ++it) {
        string the_string = *it;
        if ((the_string[0] == '<') && (the_string.size() >= 3) && 
        (the_string[the_string.size() - 1] == '>')) {
            sample_category(the_grammar, the_string, the_sample);
        }
        else {
            the_sample.push_back(the_string);
        }
    }

    return the_sample;
}