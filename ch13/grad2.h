#ifndef GUARD_grad_h
#define GUARD_grad_h

#include <iostream>
#include <algorithm>


#include "core2.h"

class Grad: public Core{
public:
	Grad() : thesis(0) {}
	Grad(std::istream& is ) { read(is); }
	double grade() const;
	std::istream& read(std::istream&);

private:
	double thesis;
protected:
	Grad* clone() const { return new Grad(*this);}
};


std::istream& Grad::read(std::istream& in)
{
	Core::read_common(in);
	in >> thesis;
	read_hw(in,homework);
	return in;
}

double Grad::grade () const
{
	return std::min(Core::grade(), thesis);
}


#endif
