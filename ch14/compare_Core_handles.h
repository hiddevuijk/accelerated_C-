#ifndef GUARD_compare_Core_handles_h
#define GUARD_compare_Core_handles_h

#include "Handle.h"
#include "Core.h"

bool compare_Core_handles(const Handle<Core>& h1, const Handle<Core>& h2)
{
	return h1->name()<h2->name();
} 


#endif
