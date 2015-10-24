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

	students.sort(compare);

	list<Student_info>::iterator iter = students.begin();
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


	return 0;
}


