#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <algorithm>
using namespace std;

/**
 * input    : a vector of integers v
 * output   : a pair of numbers in v whose sum is closest to zero
 * solution : sort the vector v. Suppose we v has size 5:
 *             _ _ _ _ _
 *            |_|_|_|_|_|
 *             0 1 2 3 4
 *
 * and let s_ij = v[i]+v[j], i<j.
 * 
 * If s_04 > 0, then since v[k] >= v[0] for 1<=k<=3, we have that s_k4 is even bigger than 0.
 * Then we can keep track of s_04 and continue the search in subarray v[0..3].
 * 
 * Similarly, if s_04 < 0, then s_0k will be even smaller than 0 for 1<=k<=3.
 * Then we can keep track of s_04 and continue the search in subarray v[1..4].
 *            
 */
pair<int,int> min_abs_sum_pair(vector<int> &v) {
  sort(v.begin(), v.end());
  int start = 0;
  int end = v.size()-1;
  pair<int,int> p(v[start],v[end]);
  while(start < end) {
    if (abs(v[start]+v[end]) < abs(p.first+p.second)) {
      p.first = v[start];
      p.second  = v[end];
    }
    if (v[end]+v[start] > 0) {
      end--;
    } else {
      start++;
    }
  }
  return p;
}

int main() {
  pair<int,int> p;
  vector<int> v = {-21, -67, -37, -18, 4, 67};
  p = min_abs_sum_pair(v);
  cout << "(" << p.first << "," << p.second << ")" << endl;
  return 0;
}
