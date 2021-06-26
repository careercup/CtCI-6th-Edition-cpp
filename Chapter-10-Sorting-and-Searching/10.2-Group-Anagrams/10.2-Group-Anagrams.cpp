// Question 10.2
// Group Anagrams
//
//  Explanation:
//  To check if two strings are anagrams of each other, we use a simple function that sorts them (by character) and
//  checks if they are the same string. To sort the string array we start from the leftmost element and compare it to
//  all other elements, moving all the anagrams to the right of it. Then we go to the first element that isn't an
//  anagram of these and do the same process until we reach the end of the array.

#include<bits/stdc++.h>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) 
{
    vector<vector<string>> result ;
        
        unordered_map<string, vector<string>> mp ;
        
        for(string c : strs )
        {
            string s=  c ;
            sort(s.begin() , s.end()) ;
                       
            mp[s].push_back(c) ;
        }
        
        for(auto c : mp)
        {
            result.push_back(c.second) ;
        }
        
        return result ;
}

int main()
{   
    int test_cases;
    cin>>test_cases ;
    while(test_cases)
    {
        int n; 
        cin>>n ;
        vector<string> str_list(n) ;
        for(int i=0 ; i<n ; i++)
        {
            cin>>str_list[i] ;
        }

        vector<vector<string>> Ans = groupAnagrams(str_list) ;
        
        //sorting the Ans-Vector which contains our Grouped Anagrams
        sort(Ans.begin() , Ans.end()); 

        //Printing the Groups
        for(int i=0 ; i<Ans.size(); i++)
        {
            for(int j=0 ; j<Ans[i].size() ; j++)
            {
                cout<<Ans[i][j]<<" " ;
            }
            cout<<endl;
        }
    }
    
    return 0;
}
