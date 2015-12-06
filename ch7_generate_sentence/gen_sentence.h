#ifndef GUARD_gen_sentence_h
#define GUARD_gen_sentence_h

#include <vector>
#include <map>
#include <string>

#include "nrand.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string,Rule_collection> Grammar;

std::vector<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);


#endif

