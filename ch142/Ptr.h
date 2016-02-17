#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

template<class T>
class Ptr {
public:
	void make_unique() {
		if(*refptr != 1) {
			--*refptr;
			refptr = new size_t(1);
			p = p? p->clone() : NULL;
		}
	}

	Ptr() : p(NULL), refptr(new size_t(1)) {}
	Ptr(T* t) : p(t), refptr(new size_t(1)) {}
	Ptr(const Ptr& h) : p(h.p), refptr(h.refptr) { ++*refptr;}

	Ptr& operator=(const Ptr&);
	~Ptr();
	operator bool() const { return p;}
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
	std::size_t* refptr;
};

template<class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	++*rhs.refptr;
	if(--*refptr == 0 ){
		delete refptr;
		delete p;
	}

	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template<class T>
Ptr<T>::~Ptr()
{
	if(--*refptr == 0) {
		delete refptr;
		delete p;
	}
}

template<class T>
T& Ptr<T>::operator*() const
{
	if(p) return *p;
	throw std::runtime_error("unbound Ptr");
}

template<class T>
T* Ptr<T>::operator->() const
{
	if(p) return p;
	throw std::runtime_error("unbound Ptr");
}

#endif
