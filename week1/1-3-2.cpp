#include <map>
#include <string>
#include <iostream>
#include <exception>
using namespace std;

template <typename Key,typename Value>
Value& GetRefStrict(map<Key, Value>&m, Key k) {
	if (m.count(k) == 0) {
		throw runtime_error{"No such key exist \n"};
	}
	else {
		return m.at(k);
	}
}


int main()
{
	map<int, string> m = { {0,"value"} };
	try {
		string& item = GetRefStrict(m, 1);
		item = "new_value";
		cout << m[0] << endl;
	}
	catch (exception& e) { cout<< e.what(); }
}