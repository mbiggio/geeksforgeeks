#include<iostream>
#include<vector>
using namespace std;

/**
 * input:    a sorted array of integers v and an integer key k
 * output:   the occurrences of k in v, or -1 if k is not in v
 * solution: modify binary search to return the smallest/biggest index 
 *           where k occurs in v, and compute the difference.
 */
int binary_search(const vector<int> &v, int k, bool findSmallest) {
  int l = 0;
  int h = v.size()-1;
  int idx = -1;
  while(l<=h) {
    int mid = l + (h-l)/2;
    if (v[mid] == k) idx=mid;
    if (findSmallest) {
      if (v[mid] >= k) h=mid-1;
      else l=mid+1;
    } else {
      if (v[mid] > k) h=mid-1;
      else l=mid+1;
    }
  }
  return idx;
}

int count_occurrencies_sorted(const vector<int> &v, int k) {
  int lower = binary_search(v,k,true);
  if (lower == -1) return -1;
  int upper = binary_search(v,k,false);
  return upper-lower+1;
}

void test1() {
  vector<int> v = {1, 1, 2, 2, 2, 2, 3};
  int k = 2;
  cout << "test1: " << count_occurrencies_sorted(v,k) << endl;
}

void test2() {
  vector<int> v = {1, 1, 2, 2, 2, 2, 3};
  int k = 3;
  cout << "test2: " << count_occurrencies_sorted(v,k) << endl;
}

void test3() {
  vector<int> v = {1, 1, 2, 2, 2, 2, 3};
  int k = 1;
  cout << "test3: " << count_occurrencies_sorted(v,k) << endl;
}

void test4() {
  vector<int> v = {1, 1, 2, 2, 2, 2, 3};
  int k = 4;
  cout << "test4: " << count_occurrencies_sorted(v,k) << endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}
