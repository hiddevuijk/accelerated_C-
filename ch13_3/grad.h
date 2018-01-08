#ifndef GUARD_GRAD_H
#define GUARD_GRAD_H

#include "core.h"

#include <iostream>
#include <string>
#include <algorithm>

class Grad: public Core {
public:
	Grad(): thesis(0) { }
	Grad(std::istream& in) { read(in);}
	double grade() const;
	std::istream& read(std::istream&);
private:
	double thesis;
};


std::istream& Grad::read(std::istream& in)
{
	Core::read_common(in);
	in >> thesis;
	read_hw(in,homework);
	return in;
}

double Grad::grade() const
{
	return std::min(Core::grade(),thesis);
}

#endif
