// Counts how many times each word occurred in the input.
#include <iostream>
#include <vector>
#include <string>
#include "read_words.h"
#include <algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::remove;

int main() {
    cout << "Please enter your text and finish your input with the end of file. "
         << "The end of file is represented by ctrl+d in linux." << endl;
    vector<string> wordVector;
    read_words(cin, wordVector);

    vector<wordInfo> wordInfoArray;
    wordInfo wordRecord;
    
    int infoIndex = 0;
    while (wordVector.size() != 0) {
        string theWord = wordVector[0];
        wordRecord.theWord = theWord;
        int frequency = 0;
        for (vector<string>::size_type j = 0; j < wordVector.size(); ++j) {
            if (theWord == wordVector[j]) {
                    frequency += 1;
            }
        }
        wordRecord.wordFrequency = frequency;

        wordInfoArray.push_back(wordRecord);

        // erase-remove idiom
        wordVector.erase(remove(wordVector.begin(), wordVector.end(), theWord), wordVector.end());
        infoIndex += 1;
    }

    cout << endl;
    for (vector<wordInfo>::size_type i = 0; i < wordInfoArray.size(); ++i) {
        cout << "The frequency of the word " << wordInfoArray[i].theWord << " is " << wordInfoArray[i].wordFrequency << "." << endl;
    }

    return 0;
}
