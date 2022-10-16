#include <iostream>


#include <string>
#include <vector>
#include <fstream>
using namespace std;

void printKlines (const string &fn, int k)
{
	if (k <= 0){
		cout << "Error invalid K value " << endl;
		return;
	}
	string line;
	int cnt=0, first=0; ifstream ifs(fn);
	vector<string> output;
	while(getline(ifs, line) && !line.empty()) {
		if(cnt >= k) {
			output[first] = line;
			first = (first+1)%k;
		}
		else {
			output.emplace_back(line);
			++cnt;
		}
	}

	int start = first;
	for (int i=0;  i< (cnt < k ? cnt : k); ++i, start = (start+1)%k) {
		cout << output[start] << endl;
	}

}

int main()
{
	string fn;// = "k_strings.txt";
	cout << "Type in the file name: " << endl;
	cin >> fn;
	
	cout << "Type the number of K last lines to print: " << endl;
	int k;
	cin >> k;
	printKlines(fn, k);
	
	return 0;
}
