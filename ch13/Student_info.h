#ifndef GUARD_student_info_h
#define GUARD_student_info_h


#include <iostream>
#include <string>
#include <stdexcept>

#include "core2.h"



class Student_info {
public:
	Student_info() : cp(0) {}
	Student_info(std::istream& is) : cp(0) { read(is); }
	Student_info(const Student_info&);
	Student_info& operator=(const Student_info&);
	~Student_info() { delete cp;}

	std::istream& read(std::istream&);
	std::string name() const {
		if(cp) return cp->name();
		else throw std::runtime_error("uninitialized Student");
	}
	double grade() const {
		if(cp) return cp->grade();
		else throw std::runtime_error("uninitialized Student");
	}
	static bool compare(const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}

private:
	Core* cp;
};


std::istream& Student_info::read(std::istream& is)
{
	delete cp;
	char ch;
	is >> ch;
	if(ch == 'U') {
		cp = new Core(is);
	} else {
		cp = new Grad(is);
	}
	return is;
}

Student_info::Student_info(const Student_info& s) : cp(0)
{
	if(s.cp)  cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
	if(&s != this) {
		delete cp;
		if(s.cp)
			cp=s.cp->clone();
		else
			cp=0;
	}
	return *this;
}

#endif



