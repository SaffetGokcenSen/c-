#include <algorithm>
#include <iterator>
#include <vector>

using std::vector;
using std::transform;
using std::back_inserter;

template <class T, class X>
X grade_analysis(const std::vector<T>& v, X x) {
    vector<double> grades;
    transform(v.begin(), v.end(), back_inserter(grades), x);
    return median(grades);
}