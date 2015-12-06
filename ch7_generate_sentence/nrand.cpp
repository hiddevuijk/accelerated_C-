#include "nrand.h"
#include <stdexcept>

using namespace::std;

int nrand(int n)
{
	if(n<=0 || n > RAND_MAX)
		throw domain_error("Argument to nrand out of range");
	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while(r>=n);

	return r;
}

