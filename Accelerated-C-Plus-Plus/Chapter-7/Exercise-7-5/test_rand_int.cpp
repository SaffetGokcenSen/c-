#include "Sentence_generation.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    cout << "Please enter an upper bound to generate 10 random integers less "
         << "than this bound." << endl;
    
    int upper_bound;
    cin >> upper_bound;
    cout << endl;

    for (int j = 0; j < 10; ++j) {
        int random_int = rand_int(upper_bound);
        cout << random_int << endl;
    }

    return 0;
}