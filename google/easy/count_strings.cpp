#include <iostream>
using namespace std;

int count_strings_rec(int n, int bcount, int ccount) {

  if (n == 0) return 1;
  int number = 0;
  number += count_strings_rec(n-1, bcount, ccount);
  if (bcount > 0) {
    number += count_strings_rec(n-1, bcount-1, ccount);
  }
  if (ccount > 0) {
    number += count_strings_rec(n-1, bcount, ccount-1);
  }
  return number;
}

int main() {
  int n;
  cin >> n;
  cout << count_strings_rec(n, 1, 2) << endl;
  return 0;
}
