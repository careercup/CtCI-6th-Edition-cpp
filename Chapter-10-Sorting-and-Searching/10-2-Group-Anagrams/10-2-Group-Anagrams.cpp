//  Created on: 11/12/2020 (dd/mm/yyyy)
//
//  Question 10.2
//  Group Anagrams
//
//  Explanation:
//  To check if two strings are anagrams of each other, we use a simple function that sorts them (by character) and
//  checks if they are the same string. To sort the string array we start from the leftmost element and compare it to
//  all other elements, moving all the anagrams to the right of it. Then we go to the first element that isn't an
//  anagram of these and do the same process until we reach the end of the array.
#include <iostream>
#include <string>
#include <algorithm>

bool anagram_check(std::string s1,std::string s2) // checks if two strings are anagrams of each other
{
    if (s1.size() != s2.size()) return false;
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    return s1 == s2;
}

void group_anagrams(std::string arr[], int size)
{
    int cur_index = 0; 
    while (cur_index < size) {
        // in each loop we start with the element at cur_index and move all the anagrams to the right of it
        for (int i = cur_index + 1; i < size; i++) {
            if (anagram_check(arr[cur_index], arr[i])) {
                cur_index++;
                std::string temp = arr[i];
                arr[i] = arr[cur_index];
                arr[cur_index] = temp;
            }
        }
        cur_index++;
    }

}


int main()
{
    // As an example, we can use:
    std::string s[6] = {"abcd", "asleep", "notananagram", "cdba", "please", "dcba"};

    // print array before
    std::cout << "Array before: ";
    for (int i = 0; i < 6; i++) {
        std::cout << s[i] << " ";
    }

    group_anagrams(s, 6);

    // print array after
    std::cout << "\nArray after: ";
    for (int i = 0; i < 6; i++) {
        std::cout << s[i] << " ";
    }

    return 0;
}