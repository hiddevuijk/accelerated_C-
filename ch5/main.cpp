#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>

#include "grade.h"
#include "Student_info.h"

using namespace::std;

int main()
{
	list<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while(read(cin,record)) {
		maxlen  = max(maxlen,record.name.size());
		students.push_back(record);
	}


	list<Student_info> failed = extract_fails(students);
	failed.sort(compare);
	students.sort(compare);

	cout << "Students passed:" << endl;
	list<Student_info>::const_iterator iter = students.begin();
	while(iter != students.end()) {

		cout << iter->name
			<< string(maxlen + 1 - iter->name.size(), ' ' );
			
		try {
			double final_grade = grade(*iter);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e ) {
			cout << e.what();
		}
		cout << endl;
		iter++;
	}		

	cout << "Students failed:" << endl;
	list<Student_info>::const_iterator iterf = failed.begin();
	while(iterf != failed.end()) {

		cout << iterf->name
			<< string(maxlen + 1 - iterf->name.size(), ' ' );
			
		try {
			double final_grade = grade(*iterf);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		} catch (domain_error e ) {
			cout << e.what();
		}
		cout << endl;
		iterf++;
	}

	return 0;
}


