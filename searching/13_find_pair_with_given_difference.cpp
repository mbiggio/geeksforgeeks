#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<int,int> find_diff(const vector<int> v, int diff) {
  if (v.size() < 2) return make_pair(-1,-1);
  unordered_map<int,int> m;
  m[v.back()] = v.size()-1;
  for (int i = v.size()-2; i>=0; --i) {
    auto it = m.find(v[i]-diff);
    if (it!=m.end()) return make_pair(i,it->second);
    it = m.find(diff+v[i]);
    if (it!=m.end()) return make_pair(i,it->second);
    m[v[i]]=i;
  }
  return make_pair(-1,-1);
}

int main() {
  vector<int> v1 = {5, 20, 3, 2, 50, 80};
  int d1 = 78;
  auto p1 = find_diff(v1,d1);
  cout << "(" << p1.first << "," << p1.second << ")" << endl;
  vector<int> v2 = {90, 70, 20, 80, 50};
  int d2 = 45;
  auto p2 = find_diff(v2,d2);
  cout << "(" << p2.first << "," << p2.second << ")" << endl;
  return 0;
}
