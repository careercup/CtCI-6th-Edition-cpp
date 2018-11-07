#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // for sort() 


bool isUniqueChars(const std::string &str){
  if (str.length() > 128){
    return false;
  }
  std::vector<bool> charSet(128);
  for (int i = 0; i < str.length(); i++){
    int val = str[i];
    if (charSet[val]){
      return false;
    }
    charSet[val] = true;
  }
  return true;
}

bool isUniqueCharsBitVector(const std::string &str) {
  //Reduce space usage by a factor of 8 using bitvector. 
  //Each boolean otherwise occupies a size of 8 bits.
  std::bitset<256> bits(0);
  for(int i = 0; i < str.length(); i++) {
    int val = str[i];
    if(bits.test(val) > 0) {
      return false;
    }
    bits.set(val);
  }
  return true;
}
bool isUniqueCharsNoDataStructure( std::string str) {
  
  std::sort(str.begin(), str.end()); // O(nlogn) sort from <algorithm>
  
  bool noRepeat = true;
  for ( int i = 0 ; i < str.size() - 1; i++){
    if ( str[i] == str[i+1] ){
      noRepeat = false;
      break;
    }
  }
  
  return noRepeat;	
}

int main(){
  std::vector<std::string> words = {"abcde", "hello", "apple", "kite", "padle"};
  for (auto word : words)
    {
      std::cout<<word<<": "<<isUniqueChars(word)<<std::endl;
    }
  std::cout<<std::endl<<"Using bit vector"<<std::endl;
  for (auto word : words)
    {
      std::cout<<word<<": "<<isUniqueCharsBitVector(word)<<std::endl;
    }
  std::cout<<std::endl<<"Using no Data Structures"<<std::endl;
  for (auto word : words)
    {
      std::cout<<word<<": "<<isUniqueCharsNoDataStructure(word)<<std::endl;
    }
  return 0;
}

