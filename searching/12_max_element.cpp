#include <iostream>
#include <vector>
using namespace std;

bool is_max(const vector<int> &v, int idx) {
  return ((idx<1 || v[idx]>=v[idx-1]) &&
          (idx>=v.size()-1 || v[idx]>=v[idx+1]));
}

int find_max(const vector<int> &v) {
  int start = 0;
  int end = v.size()-1;
  while (start<=end) {
    int mid = start + (end-start)/2;
    if (is_max(v,mid)) return mid;
    else if (mid+1<v.size() && v[mid]<v[mid+1]) start = mid+1;
    else end = mid-1;
  }
  return -1;
}

int main() {
  cout << find_max({8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}) << endl;
  cout << find_max({1, 3, 50, 10, 9, 7, 6}) << endl;
  cout << find_max({10, 20, 30, 40, 50}) << endl;
  cout << find_max({120, 100, 80, 20, 0}) << endl;
  return 0;
}
