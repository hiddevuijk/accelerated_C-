#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <vector>
#include <string>
#include <list>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);



#endif



