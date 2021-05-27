#include <limits>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int N;
	uint64_t R, side1,side2,side3;
	uint64_t mass = 0;
	uint64_t res = 0;
	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> side1 >> side2 >> side3;
		mass = (side1 * side2 * side3) * R;
		res += mass;
		mass = 0;
	}
	cout <<	res;
}