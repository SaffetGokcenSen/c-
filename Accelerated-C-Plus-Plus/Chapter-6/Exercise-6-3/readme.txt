Explanation
What does this program fragment do?

vector<int> u(10, 100);
vector<int> v;
copy(u.begin(), u.end(), v.begin());

Write a program that contains this fragment, and compile and execute it.

If such a program is written, it will give a runtime error. The error is due to 
the following line:

copy(u.begin(), u.end(), v.begin());

Instead of this line, the following should be used:

copy(u.begin(), u.end(), back_inserter(v));

A small program using the correct form is written and run.