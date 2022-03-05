// a function that reads words from an
// input stream and stores them in a vector.

#include "read_words.h"

using std::istream;
using std::vector;
using std::string;

istream& read_words(istream& theStream, vector<string>& theVector) {
    if (theStream) {
        // clean the content of the vector
        theVector.clear();

        string theString;
        while (theStream >> theString) {
            theVector.push_back(theString);
        }

        // reset the stream state for the next input
        theStream.clear();
    }

    return theStream;
}