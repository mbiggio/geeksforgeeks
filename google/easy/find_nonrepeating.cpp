#include <iostream>
#include <set>
#include <vector>
using namespace std;

void find_nonrepeating(const vector<int> &arr, set<int> &set) {
  set.clear();
  for (auto i : arr) {
    if (set.find(i) != set.end()) set.erase(i);
    else set.insert(i);
  }
}

void test1() {
  vector<int> arr = {2, 4, 7, 9, 2, 4};
  set<int> set;
  find_nonrepeating(arr,set);
  for (auto i : set) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  test1();
  return 0;
}
