#include "test.h"

int Sum(int x, int y) {
	return (x + y);
}

string Reverse(string s) {	
	reverse(begin(s), end(s));
	return s;
}

void Sort(vector<int>& nums) {
	int tmp;
	for (auto& i : nums) {
		for (auto& j : nums) {
			if (i < j) {
				tmp = i;
				i = j;
				j = tmp;
			}
		}
	}
}
