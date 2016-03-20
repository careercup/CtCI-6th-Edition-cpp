#include <iostream>
#include <string>

void print_all_parentheses_internal(size_t count, size_t opened, size_t closed, std::string arangement){

  if(closed > opened){
    return;
  }
  else if(opened > count){
    return;
  }
  else if(arangement.size()==2*count){
    std::cout << arangement << std::endl;
  }

  print_all_parentheses_internal(count,opened+1,closed,  arangement+"(");
  print_all_parentheses_internal(count,opened  ,closed+1,arangement+")");
}

void print_all_parentheses(size_t count){
  print_all_parentheses_internal(count, 0, 0, "");
}

int main(int argc, const char* argv[]) {
  print_all_parentheses(3);
  return 0;
}
