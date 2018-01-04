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
	std::istream& read(std::istream&);
	double grade() const;
	std::string name() {return n;}
};





#endif
