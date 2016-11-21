#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isUniqueChars(const string &str)
	{
		if (str.length() > 128)
		{
			return false;
		}
		vector<bool> char_set(128);
		for (int i = 0; i < str.length(); i++)
		{
			int val = str[i];
			if (char_set[val])
			{
				return false;
			}
			char_set[val] = true;
		}
		return true;
	}

int main()
	{
		vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
		}
		return 0;
	}

