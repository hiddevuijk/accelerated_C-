#include "Student_info.h"

#include <vector>
#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace::std;

int main()
{

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store data
	while(record.read(cin)) {
		maxlen = max(maxlen,record.name().size());
		students.push_back(record);
	}

	// order students
	sort(students.begin(),students.end(), Student_info::compare);

	for(int i=0;i<students.size();++i) {
		cout << students[i].name()
		     << string(maxlen+1-students[i].name().size(),' ');
		try {
			double final_grade = students[i].grade();
			cout << setprecision(3) << final_grade << endl;
		} catch (domain_error e) {
			cerr << e.what() << endl;
		}
	}


	return 0;
}
