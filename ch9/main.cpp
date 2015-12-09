#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Student_info.h"

using namespace::std;

int main()
{

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;
	
	while(record.read(cin)) {
		maxlen = max(maxlen,record.name().size());
		students.push_back(record);
	}

	sort(students.begin(),students.end(),compare);
	for(int i=0;i<students.size();++i) {
		cout << students[i].name()
			<< string(maxlen+1-students[i].name().size(),' ');
		try {
			double finalgrade = students[i].grade();
			cout << setprecision(3) << finalgrade << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
