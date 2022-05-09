#ifndef GUARD_URLS
#define GUARD_URLS
#include <vector>
#include <string>

bool not_url_char(char);

std::string::const_iterator url_beg(std::string::const_iterator, 
std::string::const_iterator);

std::string::const_iterator url_end(std::string::const_iterator, 
std::string::const_iterator);

std::vector<std::string> find_urls(const std::string&);

#endif