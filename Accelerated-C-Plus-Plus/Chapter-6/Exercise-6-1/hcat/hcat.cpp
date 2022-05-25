#include "Hcat.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::string;
using std::vector;
using std::max;
using std::transform;
using std::back_inserter;

// finds the maximum of the lengths of a vector of strings
string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for(vector<string>::size_type i = 0; i != v.size(); ++i)
    maxlen = max(maxlen, v[i].size());
    return maxlen;
}

// string addition function to be used in transform
string add(string string1, string string2) {
    return (string1 + string2);
}

// horizontally concatenates two input vectors of strings
vector<string> hcat(vector<string>& left, vector<string>& right) {
    // the maximum of the lengths of the vector of left strings
    string::size_type max_len_left = width(left);

    typedef vector<string>::size_type string_vec_size;
    string_vec_size left_vector_size = left.size();
    string_vec_size right_vector_size = right.size();

    // create a vector of spaces with varying lengths. the vector must have a 
    // length equal to that of the left vector. each element must contain spaces
    // of length equal to maximum width minus the length of the corresponding 
    // left vector element.
    vector<string> space_vector;
    for (string_vec_size i = 0; i != left.size(); ++i) {
        string spaces(max_len_left + 3 - left[i].size(), ' ');
        space_vector.push_back(spaces);
    }

    // add each element of the vector of spaces with varying lengths to each 
    // element of the left vector. use transform to make this addition.
    transform(left.begin(), left.end(), space_vector.begin(), left.begin(), add);

    // if the left vector is shorter than the right vector
    // pad spaces to the end of the left vector to equate its length to that of
    // the right vector.
    // create a vector of spaces. Each space element must be of length equal to
    // the maximum width plus 1. The length of the vector must be equal to the
    // length of the right vector minus the length of the left vector.
    // copy this space vector to the end of the left vector.
    if (left_vector_size <= right_vector_size) {
        vector<string> space_vector2;
        string spaces(max_len_left + 3, ' ');
        for (string_vec_size i = 0; i != right_vector_size - left_vector_size;
        ++i) {
            space_vector2.push_back(spaces);
        }
        copy(space_vector2.begin(), space_vector2.end(), back_inserter(left));
    }
    else {
        vector<string> space_vector2;
        // pad blanks to the end of the right vector to equate its length to 
        // that of the left vector.
        // create a vector of blanks. The length of the vector must be equal to 
        // the length of the left vector minus the length of the right vector.
        // copy this blank vector to the end of the right vector.
        string blank(1, ' ');
        for (string_vec_size i = 0; i != left_vector_size - right_vector_size;
        ++i) {
            space_vector2.push_back(blank);
        }
        copy(space_vector2.begin(), space_vector2.end(), back_inserter(right));
    }

    // add each element of the right vector to each element of the left vector.
    // use transform to make this addition.
    transform(left.begin(), left.end(), right.begin(), left.begin(), add);

    return left;
}