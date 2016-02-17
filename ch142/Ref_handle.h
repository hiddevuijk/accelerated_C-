#ifndef GUARD_Ref_handle_h
#define GUARD_Ref_handle_h


#include <stdexcept>

template<class T>
class Ref_handle {
public:
	Ref_handle() : p(NULL) {}
	Ref_handle(T* t) : p(t) , refptr(new std::size_t(1)) {}
	Ref_handle(const Ref_handle& h) 
		: p(h.p), refptr(h.refptr) {
		++*refptr;
	}

	Ref_handle& operator=(const Ref_handle&);
	~Ref_handle();

	operator bool() const { return p;}
	T& operator*() const {
		if(p) return p;
		throw std::runtime_error("unbounded Ref_handle");
	}
	T* operator->() const {
		if(p) return p;
		throw std::runtime_error("unbounded Ref_handle");
	}

private:
	T* p;
	std::size_t* refptr;

};

template<class T>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
	++*rhs.refptr;
	// free the left-hand side, destroy ptrs if appropiate
	if(--*refptr == 0) {
		delete refptr;
		delete p;
	}
	
	//copy rsh to lhf
	refptr = rhs.refptr;
	p = rhs.p;
	return *this;
}

template<class T>
Ref_handle<T>::~Ref_handle() {
	if(--*refptr == 0) {
		delete refptr;
		delete p;
	}
}



#endif
