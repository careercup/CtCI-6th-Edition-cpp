#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

bool arePermutation(std::string str1, std::string str2)
{
  // Get lengths of both strings
  int n1 = str1.length();
  int n2 = str2.length();
  
  // If length of both strings is not same, then they
  // cannot be anagram
  if (n1 != n2){
    return false;
  }
  
  // Sort both strings
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());
  // Compare sorted strings
  for (int i = 0; i < n1;  i++){
    if (str1[i] != str2[i]){
      return false;
    }
  }
  
  return true;
}

bool arePermutation2(const std::string &str1, const std::string &str2) {
  if(str1.length() != str2.length()){ 
    return false;
  }
  int count[256]={0};
  for(int i = 0; i < str1.length(); i++) {
    int val = str1[i];
    count[val]++;
  }
  for(int i = 0; i < str2.length(); i++) {
    int val = str2[i];
    count[val]--;
    if(count[val]<0) 
      return false;
  }
  return true;
}
int main() {
  // Test Method 1 - Using sort
  std::cout<<"Method 1 - Using sort"<< std::endl;
  std::string str1 = "testest";
  std::string str2 = "estxest";
 
  std::cout<<str1<<", "<<str2<<": "<<arePermutation(str1, str2)<<std::endl;
    
  str1 = "hello";
  str2 = "oellh";
  std::cout<<str1<<", "<<str2<<": " <<arePermutation(str1, str2)<<std::endl;
 
  //Test Method 2 - Using character count
  std::cout << "Method 2 - Using character count" << std::endl;
  str1 = "testest";
  str2 = "estxest";
 
  std::cout<<str1<<", "<<str2<<": "<<arePermutation2(str1, str2)<<std::endl;
 
  str1 = "hello";
  str2 = "oellh";
  std::cout<<str1<<", "<<str2<<": "<<arePermutation2(str1, str2)<<std::endl;
  return 0;
}
