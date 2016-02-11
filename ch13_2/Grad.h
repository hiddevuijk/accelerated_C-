#ifndef GUARD_Grad_h
#define GUARD_Grad_h

#include "Core.h"

#include <istream>
#include <algorithm>

class Grad: public Core {
public:
	Grad() :thesis(0) { }
	Grad(std::istream& is) { read(is); }
	double grade() const;
	std::istream& read(std::istream&);

protected:
	Grad* clone() const { return new Grad(*this); }
private:
	double thesis;
};


std::istream& Grad::read(std::istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in,homework);
	return in;
}

double Grad::grade() const
{
	return std::min(Core::grade(),thesis);
}

#endif
