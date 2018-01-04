#ifndef GUARD_VEC_H
#define GUARD_VEC_H


#include <cstddef>

void create(){ int x = 0;}
template<class T>
void create(std::size_t,const T&) { int x = 0;}
template<class it>
void create(const it, const it);
template<class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;	
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	Vec() { create(); }
	explicit Vec(std::size_t n, const T& val = T()) { create(n,val);}
	Vec(const Vec& v) { create(v.begin(),v.end());}
	

	size_type size() const { return limit - data;}
	T& operator[](size_type i){ return data[i];}
	const T& operator[](size_type i) const {return data[i];}

	iterator begin() {return data;}
	const_iterator begin() const { return data;}
	iterator end() { return limit;}
	const_iterator end() const { return end;}

	
private:
	iterator data;	// first element
	iterator limit;	// 1 past the last element

};





#endif
