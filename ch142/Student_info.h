#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include "Core.h"
#include "Grad.h"

#include <stdexcept>
#include <istream>

class Student_info {
public:
	Student_info() {}
	Student_info(std::istream& is)  { read(is);}

	std::istream& read(std::istream&);

	std::string name() const {
		if(cp) return cp->name();
		else throw std::runtime_error("uninitialized Student");
	}

	double grade() const {
		if(cp) return cp->grade();
		else throw std::runtime_error("uninitialized Student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2)
		{ return s1.name() < s2.name(); }

private:
	Handle<Core> cp;
};


std::istream& Student_info::read(std::istream& is)
{
	char ch;
	is >> ch;

	// allocate new object of the appropiate type
	// use Handle<T>(T*) to build a handle<Core> from the pointer to that object
	// call Handle<T>::operator= to assign the Handle<Core> to the LHS
	if(ch=='U') cp = new Core(is);
	else cp = new Grad(is);

	return is;
}




#endif
