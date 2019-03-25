#include <iostream>
#include <set>
#include <iterator>

std::set<std::set<int>> subsets;

void print(const std::set<int>& set) {
	for (const auto& i : set) {
		std::cout << i << " ";
	}
}

void findSubsets(const std::set<int>& set) {

	if (set.size() == 1) {
		subsets.emplace(set);
		return;
	}

	subsets.emplace(set);

	for (unsigned int i = 0; i < set.size(); ++i) {
		std::set<int> newSubset;
		for (unsigned int j = 0; j < set.size() - 1; ++j) {
			std::set<int>::iterator it = set.begin();
			std::advance(it, (j + i) % set.size());
			newSubset.emplace(*it);
		}

		findSubsets(newSubset);
			
	}
	
}

int main(int argc, char** argv) {
	std::set<int> set{ 0, 1, 2, 3 };
	findSubsets(set);

	for (const auto& set : subsets) {
		print(set);
		std::cout << std::endl;
	}

	std::cin.get();

	return 0;
}