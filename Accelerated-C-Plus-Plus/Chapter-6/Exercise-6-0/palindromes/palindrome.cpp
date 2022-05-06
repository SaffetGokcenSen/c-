#include "Palindrome.h"
#include <string>
#include <cctype>

using std::string;

bool is_palindrome(string& s) {
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        *it = tolower(*it);
    }
    return equal(s.begin(), s.end(), s.rbegin());
}