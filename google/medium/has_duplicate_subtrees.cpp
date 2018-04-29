#include <iostream>
#include <sstream>
#include <map>
using namespace std;

struct node {
  char data;
  struct node* left;
  struct node* right;
};

string compute_key(node *tree) {
  string s(3,'-');
  s[0] = (tree->left)?(tree->left->data):('-');
  s[1] = tree->data;
  s[2] = (tree->right)?(tree->right->data):('-');
  return s;
}

int compute_size(node *tree, map<string,int> &m) {
  if (!tree) {
    return 0;
  }
  int left_size  = compute_size(tree->left ,m);
  int right_size = compute_size(tree->right,m);
  int size = left_size + right_size + 1;

  cout << size << endl;

  if (size >= 2 && size <= 3 && left_size <= 1 && right_size <= 1) {
    string key = compute_key(tree);
    m[move(key)]++;
  }
  return size;
}

/**
 * Algorithm to find out if a given binary tree has 
 * a duplicate subtree of size 2 or more. 
 * The solution is based on serialization of depth-2 subtrees
 * and hashing.
 */
bool has_dup_subtree(node *tree) {
  map<string,int> m;
  compute_size(tree,m);
  for (const auto &item : m) {
    if (item.second >= 2) return true;
  }
  return false;
}


int main() {
  return 0;
}
