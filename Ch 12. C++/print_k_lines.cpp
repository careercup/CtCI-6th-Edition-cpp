#include <iostream>
#include <strstream>
#include <string>
#include <fstream>

#include <vector>
using namespace std;

const size_t k = 3;
const string filename = "k_strings.txt";
int main()
{
	vector<string> vec(k);
	ifstream ifs(filename);
	string str;
	size_t idx = 0;
	size_t lineCnt = 0;
	while (ifs.good()) {
		getline(ifs, str);
		if(str.empty()) {continue;}
		vec[lineCnt % k]= str;
		++lineCnt;
	}
	size_t end;
	if (lineCnt < k) {
		end = lineCnt;
		idx = 0;
	}
	else if (lineCnt >= k) {
		end = k;
		idx = lineCnt % k;
	}

	cout << "The " << k << " last lines are: " << endl;
	for (int i = 0 ; i < end; ++i) {

		cout << vec[(i + idx) % k] << " " << endl;
	}
	return 0;

}

