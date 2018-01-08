#ifndef GUARD_CORE_H
#define GUARD_CORE_H

#include <iostream>
#include <string>
#include <vector>

class Core{
public:
	Core(): midterm(0), final(0) { }
	Core(std::istream& in) { read(in);}
	std::string name() const { return n;}
	virtual std::istream& read(std::istream&);
	virtual double grade() const;
protected:
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;

private:
	std::string n;
};



double grade(double m, double f, std::vector<double> hw)
{
	double g =0;
	int nhw = 0;
	for(int i=0;i<hw.size();++i) {
		++nhw;
		g += hw[i];
	}
	if( nhw >0) g /= nhw;
	return 0.2*m+0.5*f+0.3*g;
}

double Core::grade() const 
{
	return  ::grade(midterm,final,homework);
}

std::istream& Core::read_common(std::istream& in)
{
	in >> n >> midterm >> final;
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


std::istream& Core::read(std::istream& in)
{
	read_common(in);
	read_hw(in,homework);
	return in;
}


bool compare(const Core& c1, const Core& c2)
{
	return c1.grade() < c2.grade();
}


#endif
