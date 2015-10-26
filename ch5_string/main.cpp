#include <iostream>
#include <string>

#include "split.h"


using namespace::std;


int main()
{
	string s;
	while(getline(cin,s)) {
		vector<string> v = split(s);
	
		for(int i=0; i<v.size();i++)
			cout << v[i] << endl;
	}



	return 0;
}




