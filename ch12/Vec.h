#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <memory>

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

	// constructor
	Vec() { create(); }

	// explicit constructor
	explicit Vec(std::size_t n, const T& val=T()) { create(n,val); }

	//destructor
	~Vec() { uncreate();}

	// return size
	size_type size() const { return avail-data;}

	// overload [] as index operator
	T& operator[](size_type i) {return data[i];}
	const T& operator[](size_type i) const { return data[i];}

	// return begin and end iterators
	iterator begin() { return data;}
	const_iterator begin() const { return data;}
	iterator end() { return avail;}
	const_iterator end() const { return avail; }

	// copy
	Vec(const Vec& v) { create(v.begin(), v.end());}

	// assignment operator =
	Vec& operator=(const Vec&);

	// push_back
	void push_back(const T& val) {
		if(avail==limit)
			grow();
		unchecke_append(val);
	}

	iterator erase(iterator);
	iterator erase(iterator,iterator);
	void clear() { uncreate(); }

private:
	iterator data;	// first element in Vec
	iterator limit;	// one past the last element in Vec
	iterator avail; // point to one past the last constructed elemend

	std::allocator<T> alloc;
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	void uncreate();

	void grow();
	void unchecked_append(const T&);

};

template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	if(&rhs!=this) {
		uncreate();
		create(rhs.begin(),rhs.end());
	}
	return *this;
}

template<class T>
void Vec<T>::create()
{
	data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data+n;
	std::uninitialized_fill(data,limit,val);
}

template<class T>
void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j-i);
	limit = avail = unitialized_copy(i,j,data);
}

template<class T>
void Vec<T>::uncreate()
{
	if(data) {
		iterator it = avail;
		while(it!=data)
			alloc.destroy(--it);
		alloc.deallocate(data,limit-data);
	}
	data=limit=0;
}

template<class T>
void Vec<T>::grow()
{
	size_type  new_size = max(2*(limit-data),ptrdiff_t(1));

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = unitialized_copy(data,avail,new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template<class T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++,val);
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator b, iterator e)
{
	if(b!=avail) {
		iterator it=e;
		iterator jt=b;
		for(iterator it,jt; it!=avail; *jt++=*it++);
		iterator newavail = avail-e+b;
		do
			alloc.destroy(--avail);
		while(avail!=newavail);
	}
	return b;
}

template<class T>
typename Vec<T>::iterator Vec<T>::erase(iterator it)
{
	return erase(it,it+1);
}




#endif
