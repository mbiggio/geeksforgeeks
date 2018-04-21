#include <iostream>
#include <vector>
#include <tuple>
#include <set>
using namespace std;

typedef tuple<int, int> doublet;
typedef tuple<int, int, int> triplet;

void triplets_zero_sum_restricted(const vector<int> &arr, int size, set <triplet> &result) {
  set<int> aset;
  for (int i = 0; i < size; ++i) {
    auto it = aset.find(-arr[size] - arr[i]);
    if (it != aset.end()) {
      triplet atriplet = make_tuple(-arr[size] - arr[i], arr[i], arr[size]);
      result.insert(atriplet);
    }
    aset.insert(arr[i]);
  }
}

void triplets_zero_sum(const vector<int> &arr, set <triplet> &result) {
  for (int i = 2; i < arr.size(); i++) {
    triplets_zero_sum_restricted(arr, i, result);
  }
}

int main() {
  vector<int> arr = {1, -2, 1, 0, 5};
  //vector<int> arr = {0,-1,2,-3,1};
  set<triplet> result;
  triplets_zero_sum(arr, result);
  for (const auto &tr : result) {
    cout << get<0>(tr) << " " << get<1>(tr) << " " << get<2>(tr) << endl;
  }
  return 0;
}
