//Question 8.2 C++ contrasting solution

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Point {
    int row;
    int column;
    Point(int r, int c) : row(r), column(c) {}
};



//////////////////////////////////////////////////////
//Implementation with memoization/caching
//////////////////////////////////////////////////////

//Checks if path is valid and simultaneously adds position to a result vector
bool getPath(int** matrix, int currRow, int currColumn, vector<Point*>& path, unordered_set<Point*>& duplicateVisits){
    
    //if out of bounds or curr position is off limits, return false
    if (currRow < 0 || currColumn < 0 || matrix[currRow][currColumn] == -1){
        return false;
    }
    
    Point* currPos = new Point(currRow, currColumn);
    
    //If we have already visited this position, then return false
    if (duplicateVisits.find(currPos) != duplicateVisits.end()){
        return false;
    }
    
    
    bool atOrigin = currRow == 0 && currColumn == 0;
    
    //Everytime robot moves up or left and it is a valid position, add the point to result vector
    if (atOrigin || getPath(matrix, currRow-1, currColumn, path, duplicateVisits) || getPath(matrix, currRow, currColumn-1, path, duplicateVisits)){
        path.push_back(currPos);
        return true;
    }
    
    //Keep track of already visited points
    duplicateVisits.insert(currPos);
    
    return false;
}

vector<Point*> getPath(int** matrix, int rows, int columns){
    //create result vector
    vector<Point*> path;
    
    //create unordered set to keep track of already visited points
    unordered_set<Point*> duplicateVisits;
    
    //Bounds checking
    if (rows != 0 || matrix != nullptr){
        //Start checking positions from bottom right to top left
        if (getPath(matrix, rows - 1, columns - 1, path, duplicateVisits)){
            return path;
        }
    }
    //Return an empty vector indicating path does not exist
    return path;
    
}


//////////////////////////////////////////////////////
//Implementation without memoization/caching
//////////////////////////////////////////////////////



//Checks if path is valid and simultaneously adds position to a result vector
//bool getPath(int** matrix, int currRow, int currColumn, vector<Point*>& path){
//    
//    //if out of bounds or curr position is off limits, return false
//    if (currRow < 0 || currColumn < 0 || matrix[currRow][currColumn] == -1){
//        return false;
//    }
//    
//    bool atOrigin = currRow == 0 && currColumn == 0;
//    
//    //Everytime robot moves up or left and it is a valid position, add the point to result vector
//    if (atOrigin || getPath(matrix, currRow-1, currColumn, path) || getPath(matrix, currRow, currColumn-1, path)){
//        Point* currPos = new Point(currRow, currColumn);
//        path.push_back(currPos);
//        return true;
//    }
//    return false;
//    
//    
//    
//    
//}
//
//vector<Point*> getPath(int** matrix, int rows, int columns){
//    //create result vector
//    vector<Point*> path;
//    
//    //Bounds checking
//    if (rows != 0 || matrix != nullptr){
//        //Start checking positions from bottom-right
//        if (getPath(matrix, rows - 1, columns - 1, path)){
//            return path;
//        }
//
//        
//    }
//    //Otherwise return an empty vector indicating path does not exist
//    return path;
// 
//}


int** createMatrix(int rows, int columns){
    //initialize number of rows
    int** matrix = new int*[rows];
    //in each row, add a new column array
    for (int i = 0; i < rows; ++i){
        matrix[i] = new int[columns];
    }
    //place values (1 indicates position is valid, -1 indicates it is invalid)
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            matrix[i][j] = 1;
        }
    }
    return matrix;
    
}

int main() {
    
    //create a 5x7 matrix (5 rows and 7 columns)
    int** matrix = createMatrix(5, 7);
    //set specific points as off-limits
    matrix[1][3] = -1;
    matrix[2][5] = -1;
    matrix[3][2] = -1;
    matrix[0][1] = -1;
    
    
    vector<Point*> path = getPath(matrix, 5, 7);
    if (path.size() == 0){
        cerr << "Path does not exist!" << endl;
        
    }
    else {
        for (int i = 0; i < path.size(); ++i){
            cout << "[" << path[i]->row << "]" << "[" << path[i]->column << "]" << endl;
        }
        
    }

}
