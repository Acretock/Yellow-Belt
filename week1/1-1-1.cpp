#include <cstdlib>
#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;


int main()
{
	int64_t res=0;
	int N, tmp;
	vector<int>temprature;
	vector<int>result;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		res += tmp;
		temprature.push_back(tmp);
	}
	res /= N;
	for (int i = 0; i < static_cast<int>(temprature.size()); i++) {
		if (temprature[i] > res) {
			result.push_back(i);
		}
	}
	if (result.size() != 0) {
		cout << result.size() << endl;
		for (auto i : result)
			cout << i << ' ';
	}
	else {
		cout << 0;
	}

    return 0;
}