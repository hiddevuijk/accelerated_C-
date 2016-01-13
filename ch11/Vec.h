#ifndef GUARD_Vec_h
#define GUARD_Vec_h

template<class T>
class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }
	explicit Vec(std::size_t n, cosnt T& val=T()) { create(n,val); }


	size_type size() const { return limit-data;}

	T& operator[](size_type i) {return data[i];}
	const T& operator[](size_type i) const { return data[i];}

	iterator begin() { return data;}
	const_iterator begin() const { return data;}

	iterator end() { return limit;}
	const_iterator const { return limit; }

	Vec(const Vec& v) { create(v.begin(), v.end());}

private:
	iterator data;	// first element in Vec
	iterator limit;	// one past the last element in Vec
}

#endif
