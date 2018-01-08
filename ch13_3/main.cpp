#include "core.h"
#include "grad.h"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class A{
public:
	A(): i(0) {}
	A(int a): i(a) {}
	int ia() {return i;}
	virtual int T() {return i;}
private:
	int i;
};

class B: public A{
public:
	B(): j(0) {}
	B(int b,int a): j(b),A(a) {}
	int ib() {return j;}
	int T() {return ia()+j;}
private:
	int j;
};
int main()
{
	A a(1);
	B b(2,1);

	A& r = b;
	A* p = &b;
	cout << r.T() << endl;
	cout << p->T() << endl;
	return 0;
}
