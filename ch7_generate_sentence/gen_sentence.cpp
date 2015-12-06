
#include "gen_sentence.h"

using namespace::std;

vector<string> gen_sentence( const Grammar& g)
{
	vector<string> ret;
	gen_aux(g,"<sentence>",ret);
	return ret;
}


bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size()-1] =='>';
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	static int count = 1;
	if(!bracketed(word)) {
		ret.push_back(word);
	} else {
		Grammar::const_iterator it = g.find(word);
		if(it==g.end())
			throw logic_error("empty rule");
		const Rule_collection& c = it->second;
		const Rule& r = c[nrand(c.size())];
		for(Rule::const_iterator i = r.begin();i!=r.end();i++)
			gen_aux(g,*i,ret);
	}
}

