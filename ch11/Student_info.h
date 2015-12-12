#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Student_info {
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
public:
	Student_info();
	Student_info(std::istream&);
	bool valid() const { return !homework.empty();}
	double grade() const;
	std::istream& read(std::istream&);
	std::string name() const {return n;}
};

Student_info::Student_info() : midterm(0), final(0) {}
Student_info::Student_info(std::istream& is) { read(is);}

double median(std::vector<double>);
double grade(double, double, const std::vector<double>& );
//istream& Student_info::read(istream&);
//double Student_info::grade() const;
double grade(double , double, double);
std::istream& read_hw(std::istream&,std::vector<double>&);

std::istream& Student_info::read(std::istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);
	return in;
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


double Student_info::grade() const
{
	return ::grade(midterm,final,homework);
}

double grade(double midterm, double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework;
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
	if (hw.size() == 0)
		throw std::domain_error("Student has done no homework");
	return grade(midterm,final,median(hw));
}


double median(std::vector<double> vec)
{
	typedef std::vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("median of empty vector");
	sort(vec.begin(), vec.end());
	vec_sz mid = size/2;
	return size % 2 == 0 ? (vec[mid] + vec[mid + 1])/2 : vec[mid];
}

bool compare(const Student_info& x, Student_info& y)
{
	return x.name() < y.name();
}

#endif

