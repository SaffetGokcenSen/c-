#include "Grade_analysis.h"

using std::cout;
using std::endl;
using std::cin;

int main() {
    cout << "Please enter the student name and surname without a separating blank."
         << " Then, please" << endl 
         << "enter the student's midterm grade and then the final grade. After "
         << "entering the" << endl 
         << "final grade start entering the homework grades. Please quit your "
         << "input with the" << endl 
         << "end-of-file character which is ctrl+d in linux."
         << endl;

    vector<Student_info> students_vector;
    Student_info student;
    while (read(cin, student)) students_vector.push_back(student);

    for (vector<Student_info>::const_iterator it = students_vector.begin(); 
    it != students_vector.end(); ++it) {
        student = *it;
        cout << "Student name: " << student.name << endl << "Midterm: " 
             << student.midterm << endl << "Final: " << student.final << endl;
        vector<double>::const_iterator it2 = student.homework.begin();
        cout << "Homework: " << *it2;
        ++it2;
        while (it2 != student.homework.end()) {
            cout << " " << *it2;
            ++it2;
        }
        cout << endl << "-----------------------------------------------------" 
             << endl;
    }

    double median = grade_analysis(students_vector, grade_aux);

    cout << "The median grade of the class is " << median << " according to the " 
         << "median analysis." << endl;

    median = grade_analysis(students_vector, average_grade);

    cout << "The median grade of the class is " << median << " according to the "
         << "average analysis." << endl;
    
    median = grade_analysis(students_vector, optimistic_median);

    cout << "The median grade of the class is " << median << " according to the "
         << "optimistic median analysis." << endl;

    return 0;
}