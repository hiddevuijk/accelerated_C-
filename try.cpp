#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace::std;

int main()
{


	vector<int> a(5,0);
	for(int i=0;i<a.size();i++) a[i] = i;
	vector<int> b(a.begin()+1,a.end());
	for(int i=0;i<b.size();i++) cout << b[i] << endl;
	return 0;
}


