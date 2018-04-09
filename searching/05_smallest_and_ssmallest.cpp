#include <iostream>
#include <vector>
using namespace std;

/**
 * input:    an array v
 * output:   the smallest and second-smallest element of v
 * solution: keep track of the smallest and second-smallest seen so far.
 *           If current element is < smaller, then s-smaller = smaller, smaller = a[i]
 *           If current element is > smaller but < s-smaller, then s-smaller = a[i]
 *           Else, continue
 */
void smallest_and_ssmallest(const vector<int> &v, int *s, int *ss) {
  if (v.size() == 0) return;
  if (v.size() == 1) {
    *s = v[0];
    return;
  }
  *s = min(v[0],v[1]);
  *ss = max(v[0],v[1]);
  for (int i = 2; i < v.size(); i++) {
    if (v[i] < *s) {
      *ss = *s;
      *s = v[i];
    } else if (v[i] > *s && v[i] < *ss) {       
      *ss = v[i];
    }
  }
}

int main() {
  vector<int> v = {12, 13, 1, 10, 34, 1};
  int s = -1;
  int ss = -1;
  smallest_and_ssmallest(v,&s,&ss);
  cout << "smallest: " << s << endl;
  cout << "second smallest: " << ss << endl;
  return 0;
}
