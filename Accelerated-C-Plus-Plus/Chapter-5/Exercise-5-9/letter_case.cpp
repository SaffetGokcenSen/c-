#include "Letter_case.h"
#include <iostream>
#include <list>
#include <string>
#include <cctype>

using std::istream;
using std::list;
using std::string;
using std::isupper;

istream& read_words(istream& input_stream, list<string>& the_picture) {
  if (input_stream) {
    // clear the previous content of the list
    the_picture.clear();
    string input_line;

    // read the input lines
    while (getline(input_stream, input_line)) {
      the_picture.push_back(input_line);
    }

    // make the stream ready for the next input
    input_stream.clear();
  }

  return input_stream;
}

bool uppercase_inclusion(const std::string& input_string) {
    // does the string contain an uppercase letter
    bool contains = false;
    // index for the letters of the string
    string::size_type i = 0;
    // check the letters of the string unless an uppercase letter is detected 
    // and the end of the string is reached.
    while (!contains && (i != input_string.size())) {
        contains = isupper(input_string[i++]);
    }

    return contains;
}

list<string> letter_case_ordering(std::list<std::string>& word_list) {
  // indicates if it is the turn of the previously examined words
  bool repeat = false;
  // traces the word which has been first sent to the end of the word list
  list<string>::size_type first_met_counter = word_list.size();
  // indicates if any word has been sent to the end of the list
  bool first_met = false;
  // used to get the order of the word first sent to the end of the list
  list<string>::size_type order = 1;
  string current_word;
  list<string>::const_iterator it = word_list.begin();
  // the words are examined for uppercase letters. the examination is finished
  // when an already examined word is in turn, that is when repeat = true, or
  // the end of the word list is reached, that is when it = word_list.end().
  while ((!repeat) && (it != word_list.end())) {
    current_word = *it;
    if (uppercase_inclusion(current_word)) {
      // if the word contains an uppercase letter, send it to the end of the 
      // list. Erase this word and get the iterator which points to the next
      // word in the list. 
      word_list.push_back(current_word);
      it = word_list.erase(it);
      // if this is the first word containing an uppercase letter, set first_met
      // to true. when the first_met_counter becomes zero, it will be the turn
      // of this word for examination. However, this will be repetition and 
      // redundant.
      if (!first_met) {
        first_met = true;
        first_met_counter = word_list.size() - order;
      }
      else {
        // if the first word containing an uppercase letter has been met,
        // decrement the counter to keep track of approaching to this word.
        --first_met_counter;
      }
    }
    else {
      // if the current word does not contain an uppercase letter, increment the 
      // iterator to get the next word. if a word with an uppercase letter has
      // already been met, keep track of getting close to the first word with
      // an uppercase letter.
      if (first_met) --first_met_counter;
      ++it;
    }
    // is the next word the first word with an uppercase letter?
    repeat = (first_met_counter == 0);
    // the order of the next word in the list
    ++order;
  }

  return word_list;
}