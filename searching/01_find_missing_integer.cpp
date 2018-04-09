#include <iostream>
#include <vector>
using namespace std;

/**
 * input:    a vector of n-1 distict integers taken from {1..n}
 * output:   the missing integer
 * solution: XOR all the numbers in the vector, XOR all the numbers form 1 to n.
 *           The result is the missing number, since all others zero-out since they are repeated.
 */
int find_missing_integer(const vector<int> &a) {
  int n = a.size()+1;
  int result = 0;
  for (int i=1; i<=n; ++i) {
    result ^= i;
  }
  for (int i = 0; i<a.size(); ++i) {
    result ^= a[i];
  }
  return result;
}

int main() {
  vector<int> v = {1, 2, 4, 5, 6};
  cout << find_missing_integer(v) << endl;
  return 0;
}
