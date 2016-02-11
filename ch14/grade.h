#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <iostream>
double grade(double midterm, double final, std::vector<double> hw)
{
	double mean_hw =0;
	for(int i=0;i<hw.size();++i)
		mean_hw += hw[i];
	return .6*final + .2* midterm + .2*mean_hw/(double)hw.size();
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	if(in) {
		hw.clear();
		double x;
		while(in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}

#endif
