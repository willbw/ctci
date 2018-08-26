#include <vector>
#include <iostream>

using namespace std;

// rotates a matrix 90 degrees
template<typename T>
void rotate_matrix(vector<vector<T>>& matrix) {
  // Reverse the rows
  reverse(matrix.begin(), matrix.end());
  for (unsigned int i = 0; i < matrix.size() - 1; i++) {
    for (unsigned int j = i+1; j < matrix.size(); j++) {
      swap(matrix[i][j], matrix[j][i]);
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
  vector<vector<char>> matrix {
    {'a', 'b', 'c', 'd'},
    {'e', 'f', 'g', 'h'},
    {'i', 'j', 'k', 'l'},
    {'m', 'n', 'o', 'p'}
  };
  print_matrix(matrix);
  cout << "\nAfter rotation\n";
  rotate_matrix(matrix);
  print_matrix(matrix);
}
