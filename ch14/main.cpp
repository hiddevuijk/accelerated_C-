
#include "Handle.h"
#include "Core.h"
#include "Grad.h"
#include "compare_Core_handles.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

using namespace::std;

int main()
{

	vector<Handle<Core> > students;
	Handle<Core> record;
	char ch;
	string::size_type maxlen = 0;

	// read and strore data
	while(cin >> ch) {
		if(ch=='U') record = new Core;
		else record = new Grad;

		record->read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	// sort records
	sort(students.begin(), students.end(), compare_Core_handles);

	// write results
	for(int i=0;i<students.size();++i) {
		cout << students[i]->name()
		     << string(maxlen+1-students[i]->name().size(),' ');
		try {
			double final_grade = students[i]->grade();
			cout << setprecision(3) << final_grade << endl;
		} catch(domain_error e) {
			cerr << e.what() << endl;
		}
	}



	return 0;
}

