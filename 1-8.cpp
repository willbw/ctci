#include <vector>
#include <iostream>

using namespace std;

void zero_matrix(vector<vector<int>>& matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  vector<bool> rows(m, false);
  vector<bool> cols(n, false);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!matrix[i][j]) {
        rows[i] = true;
        cols[j] = true;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    if (rows[i]) {
      for (int j = 0; j < n; j++) {
        matrix[i][j] = 0;
      }
    }
  }
  
  for (int j = 0; j < n; j++) {
    if (cols[j]) {
      for (int i = 0; i < m; i++) {
        matrix[i][j] = 0;
      }
    }
  }
}

// prints a matrix
template<typename T>
void print_matrix(vector<vector<T>>& matrix) {
  for (auto row : matrix) {
    for (auto col : row) {
      cout << col << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> matrix = {
    {1, 2, 0},
    {4, 3, 2},
    {3, 2, 0}
  };
  
  print_matrix(matrix);
  zero_matrix(matrix);
  cout << "\nAfter zero-ing\n";
  print_matrix(matrix);
}
