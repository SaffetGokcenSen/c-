#ifndef GUARD_GRADE_ANALYSIS
#define GUARD_GRADE_ANALYSIS

#include <vector>
#include <string>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

template <class T, class X>
X grade_analysis(const std::vector<T>& v, X x);

#endif