#ifndef GUARD_Core_h
#define GUARD_Core_h

#include "grade.h"

#include <istream>
#include <vector>
#include <string>

class Core {
	friend class Student_info;
public:
	Core() : midterm(0), final(0) {}
	Core(std::istream& is) { read(is); }
	virtual ~Core() {}
	std::string name() const;
	virtual std::istream& read(std::istream&);
	virtual double grade() const;

protected:
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;

	virtual Core* clone() const { return new Core(*this); }

private:
	std::string n;
};

std::string Core::name() const { return n;}

double Core::grade() const
{
	return ::grade(midterm,final,homework);
}

std::istream& Core::read_common(std::istream& in)
{
	in >> n >> midterm >> final;
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
	return c1.name() < c2.name();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
	return compare(*cp1,*cp2);
}

#endif
