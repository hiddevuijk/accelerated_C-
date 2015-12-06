#include <string>    // string
#include <vector>    // vector
#include <cctype>    // isspace
#include <algorithm>  // find_if
 
using std::vector;
using std::string;
using std::isspace;
using std::find_if;
 
// true if the argument is whitespace, false otherwise
// (S6.1.1/103)
bool space(char c)
{
  return isspace(c);
}
 
// false if the argument is whitespace, true otherwise
// (S6.1.1/103)
bool not_space(char c)
{
  return !isspace(c);
}
 
// Scan a line and split into words. Return a vector that contains these words.
// (S6.1.1/103)
vector<string> split(const string& str)
{
  typedef string::const_iterator iter;
  vector<string> ret;
 
  iter i = str.begin();
  while (i != str.end()) {
 
    // Ignore leading blanks
    i = find_if(i, str.end(), not_space);
 
    // Find end of next word
    iter j = find_if(i, str.end(), space);
 
    // Copy the characters in ([i, j)
    if (i != str.end())
      ret.push_back(string(i, j));
 
    // Re-initialize
    i = j;
  }
  return ret;
}
