#include <iostream>
#include <vector>
using namespace std;

void subarray_sum(const vector<int> &v, int sum, int *start, int *end) {
  *start = 0;
  *end = -1;
  int cursum = 0;

  while(1) {
    if (cursum < sum && *end+1 < v.size()) {
      cursum += v[++(*end)];
    }
    else if (cursum > sum && *start+1 < v.size()) {
      cursum -= v[(*start)++];
    }
    else return;
  }

}

void test1() {
  vector<int> v = {1, 4, 20, 3, 10, 5};
  int sum = 33;
  int start, end;
  subarray_sum(v,sum,&start,&end);
  cout << "(" << start << "," << end << ")" << endl;
}

void test2() {
  vector<int> v = {1, 4, 0, 0, 3, 10, 5};
  int sum = 7;
  int start, end;
  subarray_sum(v,sum,&start,&end);
  cout << "(" << start << "," << end << ")" << endl;
}

void test3() {
  vector<int> v = {1, 4};
  int sum = 0;
  int start, end;
  subarray_sum(v,sum,&start,&end);
  cout << "(" << start << "," << end << ")" << endl;
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}

