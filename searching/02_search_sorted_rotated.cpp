#include <iostream>
#include <vector>
using namespace std;

/**
 * input:     a sorted array shifted by a given offset
 *            a key to search in the array
 * output:    the index of the key if present, -1 if not
 * solution:  we can do something similar to binary search.
 *            Compare the key to the middle element.
 *            If equal, return the middle index.
 *            Otherwise, check if upper-half is sorted by comparing mid-element with end-point.
 *            If it is, and if a[mid] < key <= a[end], recurse on the upper-half, otherwise on the lower-half
 *            If it's not, then the lower-half must be sorted; do the symmetric process.
 */

int search_sorted_rotated(const vector<int> &a, int n, int start, int end) {
  if (start > end) return -1;
  int mid = start + (end-start) / 2;
  if (n == a[mid]) return mid;

  if (a[mid] <= a[end]) {
    if (n > a[mid] && n <= a[end]) 
      return search_sorted_rotated(a,n,mid+1,end);
    return search_sorted_rotated(a,n,start,mid-1);
  }
  else {
    if (n < a[mid] && n >= a[start]) 
      return search_sorted_rotated(a,n,start,mid-1);
    return search_sorted_rotated(a,n,mid+1,end);
  }
}

int main() {
  vector<int> v = {3,4,5,1,2};
  int num;
  cin >> num;
  cout << search_sorted_rotated(v, num, 0, v.size()-1) << endl;
  return 0;
}
