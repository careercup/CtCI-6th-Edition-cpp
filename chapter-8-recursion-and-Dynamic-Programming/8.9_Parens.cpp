//We use the second solution provided in the book.

# include<stdio.h>
# define MAX_SIZE 100

void _printParenthesis(int pos, int n, int left, int right);

/* Wrapper over _printParenthesis()*/
void printParenthesis(int n)
{
  if(n > 0)
     _printParenthesis(0, n, 0, 0);
  return;
}

void _printParenthesis(int pos, int n, int left, int right) //left/right is the number of left/right parentheses already used
{
  static char str[MAX_SIZE];

  if(left == n && right == n)                       //If both types of parentheses are used up, we print the sequence
  {
    printf("%s \n", str);
    return;
  }
  else
  {
    if(left > right) {
        str[pos] = ')';
        _printParenthesis(pos+1, n, left, right+1);  //position index always increases by 1
    }
    if(left < n) {
       str[pos] = '(';
       _printParenthesis(pos+1, n, left+1, right);
    }
  }
}

/* driver program to test above functions */
int main()
{
  int n = 4;
  printParenthesis(n);
  return 0;
}
