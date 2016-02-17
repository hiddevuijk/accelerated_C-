#ifndef GUARD_Str_h
#define GUARD_Str_h

#include "Vec.h"
#include "Ptr.h"

#include <string>

class Str{
	friend std::istream& operator>>(std::istream&, Str&);

private:
	Ptr< Vec<char> > data;
public:
	Str& operator+=(const Str& s) {
		data.make_unique();
		std::copy(s.data->begin(),s.data->end(),std::back_inserter(*data));
		return *this;
	}

	typedef Vec<char>::size_type size_type;

	Str() : data(new Vec<char>) {}
	Str(const char* cp) : data(new Vec<char>) {
		std::copy(cp,cp+std::strlen(cp),
			std::back_inserter(*data));
	}	

	Str(size_type n, char c) : data(new Vec<char>(n,c)) {}
	template<class In> Str(In i, In j) : data(new Vec<char>) {
		std::copy(i,j,std::back_inserter(*data));
	}

	char& operator[](size_type i) {
		data.make_unique();
		return (*data)[i];
	}

	const char& operator[](size_type i) const { return (*data)[i];}
	size_type size() const { return data->size();}

};

std::istream& operator>>(std::istream& is, Str& s)
{
	s.data->clear();
	char c;
	while(is.get(c) && isspace(c));

	if(is) {
		do s.data->push_back(c);
		while(is.get(c) && !isspace(c));
		if(is)
			is.unget();
	}
	return is;
}

Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}


template<>
Vec<char>* clone(const Vec<char>* vp)
{
	return new Vec<char>(*vp);
}

#endif
