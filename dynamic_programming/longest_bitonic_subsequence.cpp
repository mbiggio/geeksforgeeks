#include <iostream>
#include <vector>
using namespace std;

/**
 * Longest bitonic subsequence problem
 *   longest_bitonic_subsequence[i] = 
 *      longest_increasing_prefix[i] + longest_decresing_suffix[i] - 1
 */
int longest_bitonic_subsequence(const vector<int> &v) {

  vector<int> longest_increasing_prefix(v.size(),1);
  vector<int> longest_decreasing_suffix(v.size(),1);

  for (int i=0; i<v.size(); ++i) {
    for (int j=i-1; j>=0; --j) {
      if (v[j]<v[i]) 
        longest_increasing_prefix[i] = max(longest_increasing_prefix[i],1+longest_increasing_prefix[j]);
    }
  }
  for (int i=v.size()-1; i>=0; --i) {
    for (int j=i+1; j<v.size(); ++j) {
      if (v[j]<v[i]) 
        longest_decreasing_suffix[i] = max(longest_decreasing_suffix[i],1+longest_decreasing_suffix[j]);
    }
  }
  int result = 1;
  for (int i=0; i<v.size(); ++i) {
    result = max(result,longest_increasing_prefix[i]+longest_decreasing_suffix[i]-1);
  }
  return result;
}

int main() {
  cout << longest_bitonic_subsequence({1, 11, 2, 10, 4, 5, 2, 1}) << endl;
  cout << longest_bitonic_subsequence({12, 11, 40, 5, 3, 1}) << endl;
  cout << longest_bitonic_subsequence({80, 60, 30, 40, 20, 10}) << endl;
  return 0;
}
