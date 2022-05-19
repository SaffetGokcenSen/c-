#include "Frame.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using std::string;
using std::vector;
using std::max;
using std::transform;
using std::copy;
using std::back_inserter;

// finds the maximum of the lengths of a vector of strings
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
    maxlen = max(maxlen, v[i].size());
    return maxlen;
}

// concatenate two string inputs, the function to be used in the transform
string add(string& string1, string& string2) {
    return string1 + string2;
}

// the function to frame an input vector of strings
vector<string> frame(vector<string>& v) {
    // the framed string
    vector<string> framed;
    // the maximum of the lengths of the vector of strings is found
    string::size_type maxlen = width(v);
    // the upper and lower borders of the vector of strings
    string border(maxlen + 4, '*');

    // add the upper border of the frame
    framed.push_back(border);

    // the vector of spaces to be added during framing
    vector<string> spaces_vector;
    vector<string> partially_framed;

    // populate the vector of partially_framed
    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {
        partially_framed.push_back("* ");
    }
    
    // populate the vector of spaces
    for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {
        spaces_vector.push_back(string(maxlen - (*it).size(), ' ') + " *");
    }

    // "* " is added to the beginning of each input string
    transform(partially_framed.begin(), partially_framed.end(), v.begin(), 
    partially_framed.begin(), add);

    // the required amount of spaces and " *" are added to the end of each input
    // string
    transform(partially_framed.begin(), partially_framed.end(), 
    spaces_vector.begin(), partially_framed.begin(), add);

    // copy the framed v string to framed
    copy(partially_framed.begin(), partially_framed.end(), back_inserter(framed));

    // add the bottom border to the framed
    framed.push_back(border);

    return framed;
}