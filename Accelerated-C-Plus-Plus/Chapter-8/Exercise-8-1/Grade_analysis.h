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

double median(std::vector<double>);

double average(const std::vector<double>&);

double average_grade(const Student_info&);

double optimistic_median(const Student_info&);

template <class T, class X>
X grade_analysis(const std::vector<T>& v, X x);

#include "grade_analysis.hpp"

#endif