
#include "studentinfo.h"

using namespace std;

istream& read_hw(istream& in,vector<double>& hw)
{
	if(in) {
		double x;
		while( in >> x ) 
			hw.push_back(x);
		in.clear();
	}
	return in;
}

istream& Student_info::read(istream& in)
{

	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
}

double Student_info::grade() const
{
	double g = 0;
	int n = 0;
	for(int i=0;i<homework.size();++i){
		++n;
		g += homework[i];
	}
	if(n>0) g /= n;
	return 0.5*g+0.2*midterm+0.3*final;
}

bool compare(const Student_info& x, const Student_info& y)
{
	return x.grade() < y.grade();
}

