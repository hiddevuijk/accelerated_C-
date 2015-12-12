#include <iostream>
#include <cstddef>

using namespace::std;

int main()
{
	const size_t dim = 3;
	double coords[dim];
	*(coords+1) = 2;
	cout << coords[1] << endl <<*(coords+4)  << endl;
	



	return 0;
}

