#include <iostream>
#include <string>

using namespace std;

void printPerms(string, string = "");

int main()
{
  printPerms("abbc");
}

void printPerms(string remainder, string prefix)
{
  long length = remainder.length();
  
  if (!length) cout << prefix << endl;
  
  bool dup[128];
  
  memset(dup, false, sizeof(bool) * 128);
  
  for (int i = 0; i < length; ++i)
  {
    if (dup[remainder.at(i)]) continue;
    
    string str1 = i == 0 ? "" : remainder.substr(0,i);
    
    string str2 = i == length - 1 ? "" : remainder.substr(i+1,length);
    
    printPerms(str1 + str2, prefix + remainder.at(i));
  
    dup[remainder.at(i)] = true;
  }
}
