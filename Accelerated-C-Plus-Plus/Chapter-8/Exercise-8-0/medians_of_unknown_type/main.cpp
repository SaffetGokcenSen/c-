#include "Generic_median.h"
#include <iostream>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main() {
    cout << "Please enter some numbers separated by newlines. These numbers "
         << "should be either all integers or all reals. Please indicate the "
         << "kind of the number as follows:" << endl
         << "Please enter 'i' for integers." << endl
         << "Please enter 'd' for reals." << endl
         << "Please enter 'q' for quitting." << endl;
    
    char the_choice;
    while (cin >> the_choice) {
        if (the_choice == 'i') {
            cout << "Please enter some integers separated by newlines. Please "
                 << "quit your input with the end-of-file character which is "
                 << "ctrl+d in linux." << endl;
            vector<int> numbers;
            int the_number;
            while (cin >> the_number) {
                numbers.push_back(the_number);
            }
            int the_median = median(numbers);
            cout << "The median of the integers is " << the_median << endl;
            return 0;
        }
        else if (the_choice == 'd') {
            cout << "Please enter some reals separated by newlines. Please "
                 << "quit your input with the end-of-file character which is "
                 << "ctrl+d in linux." << endl;
            vector<double> numbers;
            double the_number;
            while (cin >> the_number) {
                numbers.push_back(the_number);
            }
            double the_median = median(numbers);
            cout << "The median of the reals is " << the_median << endl;
            return 0;
        }
        else {
            return 0;
        }
    }
}