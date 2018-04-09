#include <iostream>
#include <vector>
using namespace std;

/**
 * input:     two sorted arrays of the same length n
 * output:    the median of the merged array of length 2n
 * solution:  at each step, we can discard one half of each array, by comparing their medians
 */
double median_two_sorted_arrays(const vector<int> &a, const vector<int> &b, int a_start, int a_end, int b_start, int b_end) {

  int n = a_end-a_start+1;
  if (n == 1) return ((a[a_start] + b[b_start])/2.0);
  int a_mid = a_start + (a_end-a_start)/2;
  int b_mid = b_start + (b_end-b_start)/2;

  if (a[a_mid] <= b[b_mid]) {
    b_end = b_mid;
    a_start = (n%2)?(a_mid):(a_mid+1);
  } else {
    a_end = a_mid;
    b_start = (n%2)?(b_mid):(b_mid+1);
  }
  return median_two_sorted_arrays(a,b,a_start,a_end,b_start,b_end);
}

int main() {
  vector<int> a = {1,12,15};
  vector<int> b = {2,13,17};
  cout << median_two_sorted_arrays(a,b,0,a.size()-1,0,b.size()-1) << endl;
  return 0;
}
