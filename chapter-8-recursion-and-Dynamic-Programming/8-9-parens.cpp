#include <iostream>
#include <vector>

void print_all_parentheses(size_t count, size_t opened, size_t closed, std::string arangement){
  
  if(closed > opened){
    return;
  }
  else if(opened > count){
    return;
  }
  else if(arangement.size()==2*count){
    std::cout << arangement << std::endl;
  }

  print_all_parentheses(count,opened+1,closed,  arangement+"(");
  print_all_parentheses(count,opened  ,closed+1,arangement+")");
}

int main(int argc, const char* argv[]) {
  
  print_all_parentheses(3,0,0,"");

  return 0;
}
