
#include <stdexcept>
#include <vector>
#include <algorithm>

#include "grade.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;


double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of empty vector");
	sort(vec.begin(), vec.end());
	vec_sz mid = size/2;
	return size % 2 == 0 ? (vec[mid] + vec[mid + 1])/2 : vec[mid];
}



double grade(double midterm, double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework;
}


double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm,final,median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm,s.final,s.homework);
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}


