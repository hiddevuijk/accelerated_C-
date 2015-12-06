#ifndef GUARD_read_grammar_h
#define GUARD_read_grammar_h

#include <vector>
#include <string>
#include <iostream>
#include <map>


#include "split.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream& in);

#endif



