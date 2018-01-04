#include "studentinfo.h"

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{

	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin)) {
		maxlen = max(maxlen,record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(),compare);

	for( vector<Student_info>::size_type i=0;
		i != students.size(); ++i) {
		cout << students[i].name()
			<< string(maxlen+1-students[i].name().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		} catch(int e)  {
			cout << "fuck" << endl;
		}
	}
	return 0;
 

}


