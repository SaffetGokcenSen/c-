#include "Ascender_descender.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::istream;
using std::list;
using std::string;
using std::vector;

istream& read_words(istream& input_stream, list<string>& word_list) {
  if (input_stream) {
    // clear the previous content of the list
    word_list.clear();
    string input_line;

    // read the input lines
    while (getline(input_stream, input_line)) {
      word_list.push_back(input_line);
    }

    // make the stream ready for the next input
    input_stream.clear();
  }

  return input_stream;
}

list<Word_structure> ascender_descender_info(const list<string>& word_list) {
    // list of the structures containing word information about word name, 
    // ascender, descender content and word size
    list<Word_structure> word_info_list;
    // the word structure to be added to the structure list
    Word_structure the_struct;
    // the current word in the list
    string current_word;
    // the definition of the size type for string vectors 
    typedef string::size_type vec_sz;
    // the index for the strings of the ascenders and the descenders
    vec_sz letter_index;
    // the index for the current word letters
    vec_sz current_word_index;
    // the boolean to indicate if the word is an ascender
    bool is_ascender;
    // the boolean to indicate if the word is a descender
    bool is_descender;
    // the string of ascenders
    const string ascenders_word = "bdfhklt";
    // the string of descenders
    const string descenders_word = "gjpqy";
    const vec_sz ascenders_word_length = ascenders_word.length();
    const vec_sz descenders_word_length = descenders_word.length();
    vec_sz current_word_length;
    // the variable to hold an ascender or a descender letter
    string the_letter;
    // examine each word in the list and detect if it is ascender or descender.
    // store the word name, its ascender info, its descender info and its size
    // in a word structure. add this structure to the structure list.
    for (list<string>::const_iterator word_list_it = word_list.begin(); 
    word_list_it != word_list.end(); ++word_list_it) {
        current_word = *word_list_it;
        the_struct.the_word = current_word;
        current_word_length = current_word.length();
        the_struct.word_size = current_word_length;

        // check if any ascender letter is in the current word. quit the check
        // when the current word is detected to contain an ascender.
        letter_index = 0;
        is_ascender = false;
        while (!is_ascender && (letter_index != ascenders_word_length)) {
          the_letter = ascenders_word.substr(letter_index, 1);
          current_word_index = 0;
          while (!is_ascender && (current_word_index != current_word_length)) {
            is_ascender = the_letter == current_word.substr(current_word_index, 1);
            ++current_word_index;
          }
          ++letter_index;
        }
        the_struct.is_ascender = is_ascender;

        // check if any descender letter is in the current word. quit the check
        // when the current word is detected to contain a descender.
        letter_index = 0;
        is_descender = false;
        while (!is_descender && (letter_index != descenders_word_length)) {
          the_letter = descenders_word.substr(letter_index, 1);
          current_word_index = 0;
          while (!is_descender && (current_word_index != current_word_length)) {
            is_descender = the_letter == current_word.substr(current_word_index, 1);
            ++current_word_index;
          }
          ++letter_index;
        }
        the_struct.is_descender = is_descender;
        
        word_info_list.push_back(the_struct);
    }

    return word_info_list;
}