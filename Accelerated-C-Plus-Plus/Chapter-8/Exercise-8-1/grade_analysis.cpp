#include "Grade_analysis.h"
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <numeric>

using std::domain_error;
using std::vector;
using std::sort;
using std::transform;
using std::back_inserter;
using std::accumulate;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(vec.begin(), vec.end());
    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}