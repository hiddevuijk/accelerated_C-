#include <iostream>
#include <vector>
#include <string>

#include "Vec.h"
#include "Str.h"
using namespace::std;

int main()
{

	Vec<int> a(10.,1);
	for (int i=0;i<10;++i)
		cout << a[i] << endl;

	return 0;
}
