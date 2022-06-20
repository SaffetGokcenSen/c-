#include "Letter_grades.h"

using std::list;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::map;

// reads in grades
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

// determines the letter grades and stores them in a map from letter grades to 
// number grades
map<char, list<double> > get_letter_grades(const list<double>& grade_list) {
    // holds the distribution of the letter grades
    map<char, list<double> > letter_grade_dist;

    for (list<double>::const_iterator it = grade_list.begin(); 
    it != grade_list.end(); ++it) {
        double grade = *it;

        if (grade < 60.0) {
            letter_grade_dist['F'].push_back(grade);
        }
        else if ((grade >= 60.0) && (grade <= 69.99)) {
            letter_grade_dist['D'].push_back(grade);
        }
        else if ((grade >= 70.0) && (grade <= 79.99)) {
            letter_grade_dist['C'].push_back(grade);
        }
        else if ((grade >= 80.0) && (grade <= 89.99)) {
            letter_grade_dist['B'].push_back(grade);
        }
        else if ((grade >= 90.0) && (grade <= 100.0)) {
            letter_grade_dist['A'].push_back(grade);
        }
    }

    return letter_grade_dist;
}