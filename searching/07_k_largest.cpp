#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void swap(int &v1, int &v2) {
  int tmp = v1;
  v1 = v2;
  v2 = tmp;
}

/**
 * The classic partition algorithm used in quicksort
 */
int partition(vector<int> &v, int start, int end, int idx) {
  swap(v[end],v[idx]);
  int i=start;
  for (int j=start; j<end; j++) {
    if (v[j]>=v[end]) {
      swap(v[j],v[i++]);
    }
  }
  swap(v[end],v[i]);
  return i;
}

/**
 * An algorithm to find the k largest elements of an array.
 * It modifies the input vector such that v[0..k-1] contains
 * the k largest elements in arbitrary order.
 */
void find_k_largest(vector<int> &v, int start, int end, int k) {
  int idx = start + (rand() % (end-start+1));
  idx = partition(v,start,end,idx);
  if (idx-start+1==k) return;
  else if (idx-start+1 > k) find_k_largest(v,start,idx-1,k);
  else find_k_largest(v,idx+1,end,k-idx+start-1);
}

void print(const vector<int> &v) {
  for (auto k : v) {
    cout << k << " ";
  }
  cout << endl;
}

void test_partition() {
  vector<int> v = {5,4,3,2,1,0};
  int pivot = 2;
  print(v);
  cout << "pivot: v[" << pivot << "]=" << v[pivot] << endl;
  cout << partition(v,0,v.size()-1,pivot) << endl;
  print(v);
}

void test() {
  vector<int> v = {1,23,12,9,30,2,50};
  int k=3;
  find_k_largest(v,0,v.size()-1,k);
  for (int i=0; i<k; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  test_partition();
  test();
  return 0;
}
