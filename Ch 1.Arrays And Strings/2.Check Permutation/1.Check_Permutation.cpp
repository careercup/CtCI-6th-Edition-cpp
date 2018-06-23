#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
bool arePermutation(string str1,string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
      return false;

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    // Compare sorted strings
    for (int i = 0; i < n1;  i++)
       if (str1[i] != str2[i])
         return false;

    return true;
}

bool arePermutation_2(const string &str1, const string &str2) {
  if(str1.length() != str2.length()) 
    return false;
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

bool arePermutation_3(string str1, string str2)
{
	if (str1.length() != str2.length())
		return false;
	
	// Store characters of the first string and their counts in a hash map
	unordered_map<char, int> my_map;
	for (char c : str1)
	{
		if (!my_map.count(c))
			my_map[c] = 1;
		else
			++my_map[c];
	}
	
	// Check whether the characters in the second string are present in the hash map
	for (char c : str2)
	{
		if (!my_map.count(c) || !my_map[c])
			return false;
		else
			--my_map[c];
	}

	return true;
}

int main() {
// Test Method 1 - Using sort
    cout << "Method 1 - Using sort" << endl;
    string str1 = "testest";
    string str2 = "estxest";
    if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
    if(arePermutation(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;

//Test Method 2 - Using character count
    cout << "Method 2 - Using character count" << endl;
    str1 = "testest";
    str2 = "estxest";
    if(arePermutation_2(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if(arePermutation_2(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
  
  //Test Method 3 - Using hash map
    cout << "Method 3 - Using hash map" << endl;
    str1 = "testest";
    str2 = "estxest";
    if(arePermutation_3(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if(arePermutation_3(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
  
    return 0;
}
