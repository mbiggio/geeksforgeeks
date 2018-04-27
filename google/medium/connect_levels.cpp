#include <iostream>
#include <queue>
using namespace std;

struct Node {
  Node *left;
  Node *right;
  Node *nextRight;
  int value;
};

struct item {
  item(Node *n, int level) : n(n), level(level) {};
  Node *n;
  int level;
};

void connect(Node *tree)
{
  if (!tree) return;
  queue<item> q;
  int last_visited_level = -1;
  Node *last_visited_node = NULL;
  q.push(item(tree,0));
  while(!q.empty()) {
    item i = q.front();
    if (i.level == last_visited_level) {
      i.n->nextRight = last_visited_node;
    }
    else {
      i.n->nextRight = NULL;
    }
    last_visited_node = i.n;
    last_visited_level = i.level;
    if (i.n->right) {
      q.push(item(i.n->right,i.level+1));
    }
    if (i.n->left) {
      q.push(item(i.n->left,i.level+1));
    }
    q.pop();
  }
}

int main() {
  // TODO tests
  return 0;
}

