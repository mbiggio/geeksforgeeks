#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

bool check_border(int i, int j, vector<vector<char> > &matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  if ((i==0) || (i==rows-1) || (j==0) || (j==cols-1)) {
    return false;
  }
  return true;
}

bool add_neighbors(int i, int j, vector<vector<char> > &matrix, set<pair<int,int> > &visited, queue<pair<int,int> > &q) {
  pair<int,int> p(i,j);
  if (matrix[i][j] == 'O' && visited.find(p) == visited.end()) {
    q.push(p);
    visited.insert(p);
  }
}

void fill_visited(vector<vector<char> > &matrix, const set<pair<int,int> > &visited) {
  for (const auto &p : visited) {
    matrix[p.first][p.second] = 'X';
  }
}

void cover_region(int i, int j, vector<vector<char> > &matrix) {
  queue<pair<int,int> > q;
  set<pair<int,int> > visited;
  pair<int,int> p(i,j);
  q.push(p);
  visited.insert(p);
  while (!q.empty()) {
    pair<int, int> p = q.front();
    if (!check_border(p.first, p.second, matrix)) {
      return;
    }
    add_neighbors(i-1,j,matrix,visited,q);
    add_neighbors(i+1,j,matrix,visited,q);
    add_neighbors(i,j-1,matrix,visited,q);
    add_neighbors(i,j+1,matrix,visited,q);
    q.pop();
  }

  fill_visited(matrix, visited);
}


void cover_matrix(vector<vector<char> > &matrix) {
  int rows = matrix.size();
  if (rows == 0) return;
  int cols = matrix[0].size();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == 'O') {
        cover_region(i,j,matrix);
      }
    }
  }
}

void print_matrix(vector<vector<char> > &m) {
  int rows = m.size();
  int cols = m[0].size();
  cout << endl;
  for (int i=0; i<rows; ++i) {
    for (int j=0; j<cols; ++j) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

void test1() {
  vector<vector<char> > m = {{'X', 'X', 'X', 'X'},
                             {'X', 'O', 'X', 'X'},
                             {'X', 'O', 'O', 'X'},
                             {'X', 'O', 'X', 'X'},
                             {'X', 'X', 'O', 'O'}
                            };
  cover_matrix(m);
  print_matrix(m);
}

void test2() {
  vector<vector<char> > m = {{'X', 'O', 'X', 'X', 'X', 'X'},
                             {'X', 'O', 'X', 'X', 'O', 'X'},
                             {'X', 'X', 'X', 'O', 'O', 'X'},
                             {'O', 'X', 'X', 'X', 'X', 'X'},
                             {'X', 'X', 'X', 'O', 'X', 'O'},
                             {'O', 'O', 'X', 'O', 'O', 'O'},
                            };
  cover_matrix(m);
  print_matrix(m);
}

int main() {
  test1();
  test2();
  return 0;
}
