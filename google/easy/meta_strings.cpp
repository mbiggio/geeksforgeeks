#include <iostream>
#include <vector>
using namespace std;

bool metastrings(const string &str1, const string &str2) {
  if (str1.size() != str2.size()) return false;
  vector<int> diff_indexes;
  for (int i = 0; i < str1.size(); ++i) {
    if (str1[i] != str2[i]) {
      if (diff_indexes.size() == 2) return false;
      diff_indexes.push_back(i);
    }
  }
  if (diff_indexes.size() < 2) return false;
  return ((str1[diff_indexes[0]] == str2[diff_indexes[1]]) &&
          (str2[diff_indexes[0]] == str1[diff_indexes[1]]) );

}

void test(const string &str1, const string &str2) {
  cout << "(" << str1 << "," << str2 << ") ";
  cout << (metastrings(str1,str2)?"are ":"are not ");
  cout << "metastrings" << endl;
}

int main() {
  test("geeks","keegs");
  test("rsting","string");
  test("Converse","Conserve");
  return 0;
}
