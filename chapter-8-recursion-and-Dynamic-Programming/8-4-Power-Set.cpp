#include <iostream>
#include <vector>
#include <set>

std::set<std::vector<int>> subsets;

void print(const std::vector<int>& vec) {
	for (const auto& i : vec) {
		std::cout << i << " ";
	}
}

void findSubsets(const std::vector<int>& set) {

	subsets.emplace(set);

	if (set.size() == 2) {
		subsets.emplace(std::vector<int>{set[0]});
		subsets.emplace(std::vector<int>{set[1]});
		return;
	}

	
	
	for (int i = 0; i < set.size(); ++i) {
		std::vector<int> newSubset;
		for (int j = 0; j < set.size() - 1; ++j) {
			newSubset.push_back(set[(i + j) % set.size()]);
		}
		findSubsets(newSubset);
	}
	
}

int main(int argc, char** argv) {
	std::vector<int> vec{ 0, 1, 2, 3 };
	findSubsets(vec);

	for (const auto& set : subsets) {
		print(set);
		std::cout << std::endl;
	}

	std::cin.get();

	return 0;
}