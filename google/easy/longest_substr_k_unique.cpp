#include <iostream>
#include <map>
using namespace std;

/*
 * loop invariant:
 * - [start,end] at the beginning of the while loop is either:
 *   1 - the maximum-length k-char string ending in end
 *   2 - the minimum-length k+1-char string starting at start
 * - maxsofar is the maximum-length k-char string with
 *   1 - 0 <= s <= start
 *   2 - 0 <= e <= end
 */

string longest_substring(const string &str, int k) {
  map<char,int> curset;
  int start = 0;
  int end = -1;
  string maxsofar;

  while(1) {
    bool updated = false;
    if (end+1 < str.size() && curset.size() <= k) {
      curset[str[++end]]++;
      updated = true;
    }
    else if (start+1 < str.size() && curset.size() > k) {
      if (curset[str[start]] > 1) {
        curset[str[start++]]--;
      } else {
        curset.erase(str[start++]);
      }
      updated = true;
    }
    else updated = false;

    if (updated && curset.size() == k && end - start + 1 > maxsofar.size()) {
      maxsofar = str.substr(start, end - start + 1);
    }
    if (not updated) return maxsofar;
  }
}

void test1() {
  string str = "aabbcc";
  int k = 1;
  cout << longest_substring(str,k) << endl;
}

void test2() {
  string str = "aabbcc";
  int k = 2;
  cout << longest_substring(str,k) << endl;
}

void test3() {
  string str = "aabbcc";
  int k = 3;
  cout << longest_substring(str,k) << endl;
}

void test4() {
  string str = "aaaacc";
  int k = 3;
  cout << longest_substring(str,k) << endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}
