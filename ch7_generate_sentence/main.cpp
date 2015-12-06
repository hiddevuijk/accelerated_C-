#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>

#include "read_grammar.h"
#include "gen_sentence.h"

using namespace::std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


int main()
{

	srand(time(NULL));

	Grammar g = read_grammar(cin);
	vector<string>	sentence = gen_sentence(g);
	vector<string>::const_iterator it = sentence.begin();
	if(!sentence.empty()) {
		cout << *it;
		++it;
	}
	while(it != sentence.end()) {
		cout << ' ' << *it;
		++it;
	}
	cout << endl;


	return 0;
}


