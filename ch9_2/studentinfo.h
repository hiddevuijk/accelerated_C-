#ifndef GUARD_STUDENTINFO_H
#define GUARD_STUDENTINFO_H

#include <string>
#include <vector>
#include <iostream>

class Student_info{
private:
	std::string n;
	double midterm, final;
	std::vector<double> homework;
public:
	Student_info() : midterm(0), final(0) {}
	Student_info(std::istream& in) { read(in);}
	std::istream& read(std::istream&);
	double grade() const;
	std::string name() {return n;}
};

bool compare(const Student_info&, const Student_info&);




#endif
