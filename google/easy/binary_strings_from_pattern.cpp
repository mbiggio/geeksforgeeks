#include <iostream>
#include <set>
using namespace std;

void binary_strings_from_pattern(const string &pattern, int index, set<string> &result) {
  while (index >= 0 && pattern[index] != '?') --index;
  if (index < 0) {
    result.insert(pattern);
  } else {
    string newpattern = pattern;
    newpattern[index] = '0';
    binary_strings_from_pattern(newpattern, index-1, result);
    newpattern[index] = '1';
    binary_strings_from_pattern(newpattern, index-1, result);
  }
}

int main() {
  string pattern = "1??0?101";
  set<string> result;
  binary_strings_from_pattern(pattern, pattern.size()-1, result);
  for (const auto &str : result) {
    cout << str << endl;
  }
  return 0;
}
