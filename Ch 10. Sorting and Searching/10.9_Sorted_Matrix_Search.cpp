#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::flush;
using std::vector;
using std::pair;
using std::make_pair;

void printMatrix(const vector<vector<int>> &matrix) {
  for (auto row : matrix) {
    for (auto val : row) {
      cout << val << "\t" << flush;
    }
    cout << endl;
  }
}

pair<int, int> findElementNaive(const vector<vector<int>> & matrix, int value) {
  int row = 0;
  int col = matrix[0].size() - 1;
  while (row < matrix.size() && col >= 0) {
    if (matrix[row][col] == value) {
      return make_pair(row, col);
    } else if (value < matrix[row][col]) {
      col--;
    } else if (value > matrix[row][col]) {
      row++;
    }
  }
  return make_pair(-1, -1);
}

int main() {
  vector<vector<int>> matrix{
    {15, 20, 40, 85},
    {20, 35, 80, 95},
    {30, 55, 95, 105},
    {40, 80, 100, 120}
  };

  printMatrix(matrix);
  auto result = findElementNaive(matrix, 55);
  cout << "(" << result.first << "," << result.second << ")" << endl;

  return 0;
}
