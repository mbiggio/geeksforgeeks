#include <iostream>
#include <vector>
using namespace std;

/**
 * Imagine you have a special keyboard with the following keys:
 * Key 1:  Prints 'A' on screen
 * Key 2: (Ctrl-A): Select screen
 * Key 3: (Ctrl-C): Copy selection to buffer
 * Key 4: (Ctrl-V): Print buffer on screen appending it
 *                  after what has already been printed.
 * 
 * If you can only press the keyboard for N times (with the above four
 * keys), write a program to produce maximum numbers of A's. That is to
 * say, the input parameter is N (No. of keys that you can press), the
 * output is M (No. of As that you can produce).
 *
 * This is a dynamic programming solution.
 * To compute the maximum number of 'A's for n keystroke m(n), we use the formula:
 *
 *    m(n) = max(1+m(n-1), max_(j=0)^(n-3){m(j)*(n-j-1)})
 */
int four_keys(int n) {
  vector<int> v(n+1);
  v[0] = 0;
  for (int i=1; i<=n; i++) {
    v[i] = 1+v[i-1];
    for (int j=0; j<=i-3; j++) {
      v[i] = max(v[i],(i-j-1)*v[j]);
    }
  }
  return v[n];
}

int main() {
  cout << four_keys(3) << endl;
  cout << four_keys(7) << endl;
  cout << four_keys(11) << endl;
  return 0;
}
