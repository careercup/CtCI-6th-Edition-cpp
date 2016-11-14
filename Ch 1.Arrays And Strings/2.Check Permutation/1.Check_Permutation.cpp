#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool arePermutation(string &str1,string &str2)
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


int main()
{
    string str1 = "testest";
    string str2 = "estxest";
    if (arePermutation(str1, str2))
      cout << ("The two strings are permutation of each other") << endl;
    else
      cout << ("The two strings are not permutation of each other") << endl;
    cout << "The sorted first string is " << str1 <<endl;
    cout << "The sorted second string is " << str2 <<endl;
    return 0;
}
