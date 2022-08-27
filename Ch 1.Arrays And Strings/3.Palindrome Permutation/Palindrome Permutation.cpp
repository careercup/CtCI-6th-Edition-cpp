#include <string>
#include <bitset>
#include <vector>
#include <iostream>

using namespace std;

int getCharNumber(const char & c){
    int a = (int) 'a';
    int z = (int) 'z';
    int A = (int) 'A';
    int Z = (int) 'Z';
    int val = (int) c;
    if(a <= val && val <= z){
        return val - 'a';
    }
    else if(A <= val && val <= Z){
        return val - 'A';
    }
    return -1;
}


vector <int> buildCharFrequencyTable(string phrase){
    vector <int> table(getCharNumber('z') - getCharNumber('a') + 1, 0);
    for(char &c : phrase){
        int x = getCharNumber(c);
        if(x != -1){
            table[x]++;
        }
    }
    return table;
}


bool checkMaxOneOdd(vector<int> &table)
{
    bool foundOdd = false;
    for (auto count : table)
    {
        if (count % 2 == 1)
        {
            if (foundOdd)
            {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}

bool isPermutationOfPalindrome(const string &phrase)
{
    vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}

bool isPermutationOfPalindrome_bitwise(const string &phrase)
{
    const int numChar = 26;
    bitset<numChar> table(0);
    for (const char& c : phrase)
    {
        const int hash = getCharNumber(c);
        if (hash == -1)
        {continue;}
        table.flip(hash);
    }
    const int summary = table.to_ulong();
    const bool isPowerOf2 = ((summary) & (summary-1)) == 0;
    return isPowerOf2;
}

#define TEST(pFunc, pattern)                                \
    do {                                                    \
        cout << "[" #pFunc "]" << endl;                     \
        cout << "- Pattern: " << pattern << endl;           \
        cout << "- Result : " << pFunc(pattern) << endl;    \
    } while (0)

int main(int argc, const char *argv[])
{
    vector<string> patterns{
        "",
        "a",
        "ab",
        "Tact Coa",
        "Rats live on no evil st",
        "Rats live on no evil star"
        };
    for (auto& pattern: patterns)
    {
        TEST(isPermutationOfPalindrome, pattern);
    }
    for (auto& pattern: patterns)
    {
        TEST(isPermutationOfPalindrome_bitwise, pattern);
    }
    return 0;
}
