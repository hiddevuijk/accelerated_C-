#ifndef GUARD_Str_h
#define GUARD_Str_h

#include "Vec.h"
#include <string.h>
class Str{
	typedef Vec<char>::size_type size_type;

	Str();

	Str(size_type n, char c) : data(n,c) {}

	Str(const char* cp) {
		std::copy(cp, cp+strlen(cp), std::back_inserter(data));
	}

	template<class In> Str(In b, In e) {
		std::copy(b,e,std::back_inserter(data));
	}

private:
	Vec<char> data;
};


#endif
