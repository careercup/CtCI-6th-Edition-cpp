#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int GRID_SIZE = 8;

bool checkValid(vector<int> columns, int row1, int col1) {

	for (int row2 = 0; row2 < row1; row2++) {
		int col2 = columns[row2];

		// check if they are in the same column
		// we don't need to check rows since always row2 < row1
		if (col1 == col2) {
			return false;
		}

		// check if they are in the same diaganol
		if (abs(col2 - col1) == abs(row1 - row2)) {
			return false;
		}
	}

	return true;
}

void placeQueens(int row, vector<int> &columns, vector<vector<int> > &results) {
	if (row == GRID_SIZE) {
		results.push_back(columns);
	}
	else {
		for (int col = 0; col < GRID_SIZE; col++) {
			if (checkValid(columns, row, col)) {
				columns[row] = col;
				placeQueens(row + 1, columns, results);
			}
		}

	}
}

void drawLine() {
	for (int i = 0; i < GRID_SIZE * 2 + 1; i++)
		cout << '-';
	cout << endl;
}

void printBoard(vector<int> columns) {
	drawLine();
	for (int i = 0; i < GRID_SIZE; i++) {
		cout << "|" ;
		for (int j = 0; j < GRID_SIZE; j++) {
			if (columns[i] == j) {
				cout << "Q|" ;
			}
			else {
				cout << " |";
			}
		}
		cout << endl;
		drawLine();
	}
	cout << endl;
}

void printBoards(vector<vector<int >> columns) {
	int numSolutions = columns.size();
	for (int i = 0; i < numSolutions; i++) {
		printBoard(columns[i]);
	}
}

int main() {
	vector<int> columns(GRID_SIZE, -1);
	vector<vector<int> > results;
	placeQueens(0, columns, results);
	printBoards(results);
	return 0;
}