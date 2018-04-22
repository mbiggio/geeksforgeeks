#include <iostream>
#include <string>
#include <map>
using namespace std;


bool is_interleave(int i, int j, const string &a, const string &b, const string &c, map< pair<int,int>, bool > &s) {
  if (s.find(pair<int,int>(i,j)) == s.end()) {
    bool is_int = false;
    if (i+1 <= a.size()) {
      is_int ^= (c[i+j] == a[i] && is_interleave(i+1,j,a,b,c,s));
    }
    if (!is_int && j+1 <= b.size()) {
      is_int ^= (c[i+j] == b[j] && is_interleave(i,j+1,a,b,c,s));
    }
    s[pair<int,int>(i,j)] = is_int;
  }
  return s[pair<int,int>(i,j)]; 
}

bool is_interleave(const string &a, const string &b, const string &c) {
  if (a.size() + b.size() != c.size()) return false;
  map< pair<int,int>, bool > s;
  s[pair<int,int>(a.size(),b.size())] = true;;
  return is_interleave(0,0,a,b,c,s);
}

void test1() {
  string a("YX");
  string b("X");
  string c("XXY");
  cout << is_interleave(a,b,c) << endl;
}

void test2() {
  string a("XY");
  string b("X");
  string c("XXY");
  cout << is_interleave(a,b,c) << endl;
}

int main() {
  test1();
  test2();
  return 0;
}
