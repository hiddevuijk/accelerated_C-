#ifndef GUARD_functions_h
#define GUARD_functions_h

#include <vector>

double grade(double midterm, double final, const std::vector<double>& hw)
{
	if (hw.size()==0)
		throw domain_error("student has done no homework");
	return grade(midterm,final,median(hw));
}

istream& read_hw(istream& in, std::vector<double>& hw)
{
	if(in) {
		he.clear();

	double x;
	while (in>>x)
		hw.push_back(x);

	in.clear();

	return in;
}






#endif

