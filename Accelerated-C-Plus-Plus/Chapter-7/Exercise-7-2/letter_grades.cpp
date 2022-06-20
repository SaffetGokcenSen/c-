#include "Letter_grades.h"

using std::list;
using std::istream;
using std::cin;
using std::cout;
using std::endl;

list<double> read_grades(istream&) {
    // list of the grades
    list<double> grade_list;
    // the grade
    double grade;

    cout << "Please enter each grade number on a single line. Please quit your "
         << "input with the end-of-file character which is ctrl+d in linux." 
         << endl;

    while(cin >> grade) {
        // add the entered grade to the list
        grade_list.push_back(grade);
    }

    return grade_list;
}