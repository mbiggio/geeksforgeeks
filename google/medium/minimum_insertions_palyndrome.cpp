#include <iostream>
#include <map>
using namespace std;

typedef map<pair<int,int>,int> table;

/**
 * Dynamic programming algorithm for finding
 * the minimum number of character insertions necessary
 * to make a palyndrome from a given string.
 */
int minimum_insertion_palyndrome(const string &s, int i, int j, table &t) {
  if (t.find(make_pair(i,j)) == t.end()) {
    if (i>=j) t[make_pair(i,j)] = 0;
    else {
      int val = min(1 + minimum_insertion_palyndrome(s,i+1,j,t),
                    1 + minimum_insertion_palyndrome(s,i,j-1,t));
      if (s[i] == s[j]) {
        val = min(val, minimum_insertion_palyndrome(s,i+1,j-1,t));
      }
      t[make_pair(i,j)] = val;
    }
  }
  return t[make_pair(i,j)];
}

void test(const std::string &s) {
  table t;
  cout << minimum_insertion_palyndrome(s,0,s.size()-1,t) << endl;
}

int main() {
  test("ab");
  test("aa");
  test("abcd");
  test("abcda");
  test("abcde");
  return 0;
}


