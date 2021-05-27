#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int n_of_perm=1;
	for (int i = 1; i <= N; i++) {
		n_of_perm*=i;
	}
	vector<int> source_permutations;
	for (int i = 0; i < N; i++) {
		source_permutations.push_back(i+1);
	}
	vector<int> is_perm;

	prev_permutation(source_permutations.begin(), source_permutations.end());
	for (auto j : source_permutations) {
		cout << j << ' ';
	}
	cout << endl;
	for (int i = 1; i < n_of_perm; i++) {
		if (prev_permutation(source_permutations.begin(), source_permutations.end())) {
			for (auto j : source_permutations) {
				cout << j << ' ';
			}
			cout << endl;
		}		
	}
}