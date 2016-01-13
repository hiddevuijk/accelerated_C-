#include "Vec.h"

#include <iostream>
#include <string>
#include <iomanip>

using namespace::std;

int main()
{

	Vec<double> a(10,.2);
	for(int i=0;i<10;++i)
		cout << a[i] << endl;

	return 0;
}

