#include <iostream>
#include <set>
#include <map>
using namespace std;

string find_largest(const string &str, const set<string> &dict) {
  map<char,int> strmap;
  for (auto c : str) {
    strmap[c]++;
  }

  string result = "";

  for (const auto &word : dict) {
    map<char,int> wordmap;
    bool matches = true;
    for (auto c : word) {
      wordmap[c]++;
      if (strmap.count(c) == 0 || wordmap[c] > strmap[c]) {
        matches = false;
        break;
      }
    }
    if (matches && word.size() > result.size()) {
      result = word;
    }
  }

  return result;
}

void test1() {
  set<string> dict = {"ale", "apple", "monkey", "plea"};
  string str = "abpcplea"; 
  cout << "longest matching: " << find_largest(str,dict) << endl;
}

void test2() {
  set<string> dict = {"pintu", "geeksfor", "geeksgeeks", " forgeek"};
  string str = "geeksforgeeks"; 
  cout << "longest matching: " << find_largest(str,dict) << endl;
}
int main() {
  test1();
  test2();
  return 0;
}
