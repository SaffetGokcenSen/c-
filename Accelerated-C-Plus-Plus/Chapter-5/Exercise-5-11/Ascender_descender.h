#ifndef GUARD_ASCENDER_DESCENDER
#define GUARD_ASCENDER_DESCENDER

#include <iostream>
#include <list>
#include <string>

std::istream& read_words(std::istream&, std::list<std::string>&);

struct Word_structure {
    std::string the_word;
    bool is_ascender;
    bool is_descender;
    std::string::size_type word_size;
};

std::list<Word_structure> ascender_descender_info(const std::list<std::string>&);

#endif