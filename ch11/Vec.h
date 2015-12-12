#ifndef GUARD_Vec_h
#define GUARD_Vec_h

template <class T> class Vec {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef std::ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	size_type size() const { return limit - data; }

	T& operator[](size_type i) {return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return limit; }
	const_iterator end() const { return limit; }

	Vec() { create(); }
	explicit Vec(std::size_t n, const T& val = T()) { create(n,val); }
	Vec( const Vec& v) { create(v.begin(), v.end() ); }

	Vec& operator=(const Vec&);

private:
	iterator data;
	iterator limit;
};



template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	if(&rhs !=this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}


#endif
