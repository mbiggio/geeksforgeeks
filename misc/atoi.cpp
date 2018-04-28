#include <iostream>
using namespace std;

int myatoi(const char *s) {
  int n=0;
  bool flip = (*s=='-');
  if (flip) ++s;
  while(*s!='\0') {
    if (*s<'0' || *s>'9') return 0;
    n*=10;
    n+=(*(s++)-'0');
  }
  return (flip)?(-n):n;
}

int main() {
  cout << myatoi("123456") << endl;
  cout << myatoi("1234560") << endl;
  cout << myatoi("0123456") << endl;
  cout << myatoi("-123456") << endl;
  cout << myatoi("-123456a") << endl;
  cout << myatoi("-123c456") << endl;
  return 0;
}
