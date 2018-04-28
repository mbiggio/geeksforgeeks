#include <iostream>
#include <map>
#include <set>
using namespace std;

map<int,bool> m;

/**
 * Dynamic programming algorithm (with memoization) to test if a given string
 * can be broken into words belonging to a given dictionary.
 * Multiple occurrence of the same dictionary word are allowed.
 */
bool can_be_broken(const string &s, int i, const set<string> &d) {
  if (m.find(i) == m.end()) {
    m[i] = false;
    for (int j=i+1; j<=s.size(); ++j) {
      m[i] = (d.find(s.substr(i,j-i)) != d.end()) &&
             (can_be_broken(s,j,d));
      if (m[i]) break;
    }
  }
  return m[i];
}

bool can_be_broken(const string &s, const set<string> &d) {
  m.clear();
  m[s.size()] = true;
  return can_be_broken(s,0,d);
}

void test(const string &s) {
  set<string> d = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", 
                    "cream", "icecream", "man", "go", "mango"};
  cout << can_be_broken(s,d) << endl;
}

int main() {
  test("ilike");
  test("ilikesamsung");
  test("ilikes");
  test("samsungilikecream");
  test("creamlikecream");
  return 0;
}
