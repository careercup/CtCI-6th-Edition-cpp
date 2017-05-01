#include <iostream>
#include <vector>
#include <deque>

#define COUNT 3

using namespace std;

vector<deque<char>> * print_all_parentheses_internal(size_t count);

void print_all_parentheses(size_t count);

int main()
{
  print_all_parentheses(COUNT);
  return 0;
}

vector<deque<char>> * print_all_parentheses_internal(size_t count)
{
  if (count == 1)
  {
    deque<char> d;
    d.push_back('(');
    d.push_back(')');
    
    vector<deque<char>> * v = new vector<deque<char>>();
    
    v->push_back(d);
    
    return v;
  }
  
  vector<deque<char>> * v = print_all_parentheses_internal(count - 1);
  
  long size = v->size();
  
  for (int i = 0; i < size; ++i)
  {
    deque<char> tmp1 = v->at(i);
    deque<char> tmp2 = v->at(i);
    
    v->at(i).push_front(')');
    v->at(i).push_front('(');
    
    tmp1.push_front('(');
    tmp1.push_back(')');
    
    v->push_back(tmp1);
    
    if (i)
    {
      tmp2.push_back('(');
      tmp2.push_back(')');
      
      v->push_back(tmp2);
    }
  }
  
  return v;
}

void print_all_parentheses(size_t count)
{
  vector<deque<char>> * v = print_all_parentheses_internal(count);
  
  long size = v->size();
  
  for (int i = 0; i < size; ++i)
  {
    deque<char>::iterator it = v->at(i).begin();
    
    while (it != v->at(i).end()) cout << *it++;
    
    cout << endl;
  }
  
  delete v;
}
