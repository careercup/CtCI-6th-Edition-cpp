#include <iostream>
#include <cmath>
using namespace std;

const int queens=8;

int board[queens];
int count = 0;

bool check(int n) {
  for(int i=0;i<n;i++) {
    if(board[i]==board[n])
      return false;
    if((n-i)==abs(board[n]-board[i]))
      return false;
  }
  return true;
}

void place(int row) {
  if(row==queens) {
    count++;
    for(int j=0;j<queens;j++)
      cout<<board[j]<<" ";
    cout<<endl;
    return;
  }
  for(int col=0;col<queens;col++) {
    board[row] = col;
    if(check(row))
      place(row+1);
  }
}

int main() {
  place(0);
  cout<<count;
	return 0;
}
