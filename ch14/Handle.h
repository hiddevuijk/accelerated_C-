#ifndef GUARD_Handle_h
#define GUARD_Handle_h

#include <stdexcept>

template<class T>
class Handle {
public:
	Handle() : p(NULL) { }
	Handle(const Handle& s) : p(NULL) { if(s.p) p=s.p->clone(); }
	Handle& operator=(const Handle&);
	~Handle() { delete p;}

	Handle(T* t) : p(t) {}

	operator bool() const {return p;}
	T& operator*() const;
	T* operator->() const;

private:
	T* p;
};



template<class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
	if(&rhs!=this) {
		delete p;
		p = rhs.p ? rhs->clone() : NULL;
	}
	return *this;
}

template<class T>
T& Handle<T>::operator*() const
{
	if(p) return *p;
	throw std::runtime_error("unbound Handle");
}

template<class T>
T* Handle<T>::operator->() const
{
	if(p) return p;
	throw std::runtime_error("unbound Handle");
}



#endif
