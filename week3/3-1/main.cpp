#include <iostream>
#include "test.h"

using namespace std;

int main()
{
	vector<int> vec = { -9,5,7,6,3,2,1 };
	Sort(vec);
	for (auto i : vec)
		cout << i << ' ';
	string s = "reverse";
	string rev = Reverse(s);
	cout << endl << s << ' ' << rev << endl << Sum(3, 20);
}