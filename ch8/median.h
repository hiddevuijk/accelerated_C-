#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <algorithm>

template<class T>
T median(std::vector<T> v)
{
	typedef typename std::vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	sort(v.begin(),v.end());
	vec_sz mid = size/2;
	return size % 2 ==0 ? (v[mid]+v[mid+1])/2 : v[mid];
	
}

#endif

