#ifndef GUARD_read_words
#define GUARD_read_words

#include <iostream>
#include <vector>
#include <string>

std::istream& read_words(std::istream&, std::vector<std::string>&);

struct wordInfo {
        std::string theWord;
        int wordFrequency;
};

#endif
