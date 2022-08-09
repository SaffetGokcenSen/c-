#ifndef GUARD_GRADE_ANALYSIS
#define GUARD_GRADE_ANALYSIS

#include <vector>
#include <string>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

double grade(double, double, double);

double grade(const Student_info&);

double grade_aux(const Student_info&);

double median_analysis(const std::vector<Student_info>&);

double average(const std::vector<double>&);

double average_grade(const Student_info&);

double average_analysis(const std::vector<Student_info>&);

template <class T, class X>
X grade_analysis(const std::vector<T>& v, X x);

#endif