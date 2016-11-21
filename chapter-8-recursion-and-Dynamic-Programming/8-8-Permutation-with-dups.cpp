#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void findPermutations(string curr, map<char,int> m, vector<string>& res, int n){

	int curr_length = curr.length();
	if (n==curr_length){
		res.push_back(curr);
		return;
	}

	for (map<char,int>::iterator i = m.begin(); i!=m.end(); i++){
		if (i->second!=0){
			char c = i->first;
			string f = curr+c;
			i->second--;
			findPermutations(f,m,res,n);
			i->second++;
		}
	}
}

int main()
{
	string s = "abbc";
	string curr ="";
	map <char, int> m;
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (m.find(s[i])!=m.end())
			m.find(s[i])->second++;
		else
			m.insert(make_pair(s[i],1));
	}
	vector<string> res;
	findPermutations(curr,m,res,n);
	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
