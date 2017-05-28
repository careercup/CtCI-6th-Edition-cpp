#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

#define ALPHABET_SIZE 256

/* Returns whether all the characters in a string are unique using an array of
booleans to track which characters have been used. The time complexity is O(n),
as the string only needs to be traversed once. It uses O(k) additional space for
the array, where k is the alphabet size. */
bool isUniqueChars(const string &str){
	/* A string with more characters than there are in the alphabet will 
	necessarily have duplicates. This optimization technically reduces the
	time complexity to O(min(n, k)). This same optimization can also be applied
	to any of the other approaches below. */	
	if (str.length() > ALPHABET_SIZE) {
		return false;
	}
	
	bool char_set[ALPHABET_SIZE] = {};
	for (int i = 0; i < str.length(); i++) {
		unsigned char val = str[i];

		if (char_set[val]) {
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

/* Returns whether all the characters in a string are unique using a bitset
track which characters have been used. Similar to the above function, the time 
complexity is O(n) and it uses O(k) additional space for the bistet, where k 
is the alphabet size. However, this version uses 8 times less space (remeber 
that constant factors are ignored in Big O notation). */
bool isUniqueChars_bitvector(const string &str) {
	//Reduce space usage by a factor of 8 using bitvector. 
	//Each boolean otherwise occupies a size of 8 bits.
	bitset<ALPHABET_SIZE> bits(0);
	for (int i = 0; i < str.length(); i++) {
		unsigned char val = str[i];
		if (bits.test(val)) {
			return false;
		}
		bits.set(val);
	}
	return true;
}

/* Returns whether all the characters in a string are unique by checking each
character in the string against every other character. The time complexity is 
O(n^2), but uses only O(1) additional space. */
bool isUniqueChars_noDS_bruteforce(const string &str) {
	int n = str.length();
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (str[i] == str[j]) {
				return false;
			}
		}
	}
	return true;	
}

/* Returns whether all the characters in a string are unique by sorting the 
charaters in the string and comparing adjacent characters. This still uses O(1) 
additional space, but the time complexity is reduced to O(n log n). The sorting
take O(n log n) time, and the comparisongs take O(n). */
bool isUniqueChars_noDS_sort(string str) {
	/* Sort the string using heap sort. Unlike other O(n log n) sorting 
	algorithms, heapsort does not require auxiliary space. */
	std::make_heap(str.begin(), str.end());
	std::sort_heap(str.begin(), str.end());
	
	int n = str.length();
	for (int i = 0; i < n-1; i++) {
		if (str[i] == str[i+1]) {
			return false;
		}
	}
	return true;	
}

int main(){
	vector<string> words;
	
	/* Simple test cases. */
	words.push_back("a"); //true
	words.push_back("aa"); //false
	words.push_back("ab"); //true
	words.push_back("abcde"); //true
	words.push_back("hello"); //false
	words.push_back("abcdefghijklmnopqrstuvwxyzz"); //false
		
	/* Empty string or whitespace only test cases. */
	words.push_back(""); //true
	words.push_back(" "); //true
	words.push_back("  "); //false
	words.push_back("\t\n"); //true
	words.push_back("\n\n"); //false
	
	/* Test all types of characters work (upper and lower alpha, numbers, 
	symbols, and extended ASCII. */
	words.push_back("ABC"); //true
	words.push_back("ABCA"); //false
	words.push_back("AaBbCc"); //true
	words.push_back("1"); //true
	words.push_back("12345"); //true
	words.push_back("1234562"); //false
	words.push_back("$#?^&"); //true
	words.push_back("$#?^&$@"); //false
	words.push_back("\x80\xC8\xFF"); //true
	words.push_back("\x80\xC8\xFF\x80"); //false
	
	cout << endl << "Using boolean array" << endl;
	for (auto word : words)	{
		cout << word << string(": ") << boolalpha << isUniqueChars(word) << endl;
	}
	
	cout << endl << "Using bit vector" << endl;
	for (auto word : words)	{
		cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) << endl;
	}
	
	cout << endl << "Using no Data Structures, brute force method" << endl;
	for (auto word : words)	{
		cout << word << string(": ") << boolalpha << isUniqueChars_noDS_bruteforce(word) << endl;
	}
	
	cout << endl << "Using no Data Structures, sorting method" << endl;
	for (auto word : words)	{
		cout << word << string(": ") << boolalpha << isUniqueChars_noDS_sort(word) << endl;
	}		
	return 0;
}
