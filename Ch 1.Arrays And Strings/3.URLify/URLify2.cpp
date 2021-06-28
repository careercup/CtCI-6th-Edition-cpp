#include <string>

#include <iostream>
using namespace std;
/* in this solution we are using C++ stl/std style */
string URLify(const string &str)
{
	int spacesCnt = 0;
	string res;

	for (auto &is : str) {
		if (is == ' ') {
			++spacesCnt;
		}
	}
//	cout << "# of spaces: " << spacesCnt << endl;
	auto newSize = str.size() + 2*spacesCnt;
	res.resize(newSize);
	cout << " res new size is: " << res.size() << endl;
	int is=0, ir=0;
	while (is < str.size()) {
		if (str[is] != ' ') {
			res[ir] = str[is];
		}
		else if (str[is] == ' ') {
			res[ir++] = '%';
			res[ir++] = '2';
			res[ir] = '0';
		}
		++is; ++ir;
	}
	return res;
}

int main()
{
	string s = URLify("This is John Smith");
	cout << " the new string is: " << s << endl;
	return 0;
}
