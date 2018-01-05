#ifndef GUARD_VEC_H
#define GUARD_VEC_H


#include <cstddef>
#include <memory>

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
	~Vec() { uncreate();}	

	size_type size() const { return avail - data;}
	T& operator[](size_type i){ return data[i];}
	const T& operator[](size_type i) const {return data[i];}
	Vec& operator=(const Vec&);

	iterator begin() {return data;}
	const_iterator begin() const { return data;}
	iterator end() { return avail;}
	const_iterator end() const { return end;}

	void push_back(const T& val) {
		if(avail == limit) grow();
		unchecked_append(val);
	}
	
private:
	iterator data;	// first element
	iterator avail; // 1 past the last element
	iterator limit;	// 1 past the last allocated element

	std::allocator<T> alloc;

	void create();
	void create(size_type,const T&);
	void create(const_iterator, const_iterator);
	void uncreate();
	void grow();
	void unchecked_append(const T&);

};

template<class T>
void Vec<T>::create()
{
	data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data,limit,val);
}

template<class T> 
void Vec<T>::create(const_iterator i,const_iterator j)
{
	data = alloc.allocate(j-i);
	limit = avail = std::uninitialized_copy(i,j,data);
}

template<class T>
void Vec<T>::uncreate()
{
	if(data) {
		iterator it = avail;
		while(it != data)
			alloc.destroy(--it);
		alloc.deallocate(data,limit-data);
	}
	data = limit = avail = 0;
}

template<class T>
void Vec<T>::grow()
{
	size_type new_size = max(2*(limit-data),ptrdiff_t(1));
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = unitialized_copy(data,avail,new_data);
	
	uncreate();
	data = new_data;
	avail = new_avail;
	limit = data+new_size;
}

template<class T>
void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++,val);
}






template<class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	if(&rhs != this) {
		uncreate();
		create(rhs.begin(),rhs.end());
	}
	return *this;
}





#endif
