#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void operation(string& res, const char& op,const int& num) {
	if (op == '+') {
		res = res + " + " + to_string(num);
	}
	if (op == '-') {
		res = res + " - " + to_string(num);
	}
	if (op == '*') {
		res = res + " * " + to_string(num);
	}
	if (op == '/') {
		res = res + " / " + to_string(num);
	}
}

void braces_post(string& res, char op, char next) {
	if (next != '\0') {
		if ((op == '+' || op == '-') && (next == '*' || next == '/')) {
			res += ')';
		}
	}
}
void braces_pre(string& res, char op, char next) {
	if (next != '\0') {
		if ((op == '+' || op == '-') && (next == '*' || next == '/')) {
			res = '(' + res;
		}
	}
}

int main()
{
	int x;
	int N;
	string tmp;
	vector<char> operations;
	vector<int> nums;
	cin >> x >> N;
	string res = to_string(x);
	for (int i = 0; i <= N; i++) {
		getline(cin, tmp);
		if (i != 0) {
			operations.push_back(tmp[0]);
			nums.push_back(stoi(tmp.substr(2, tmp.size() - 2)));
		}
	}
	operations.push_back('\0');
	for (int i = 0; i < N; i++) {
		braces_pre(res, operations[i], operations[i + 1]);
		operation(res, operations[i], nums[i]);
		braces_post(res, operations[i], operations[i + 1]);
	}
	cout << res;
}