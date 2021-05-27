#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (range_end - range_begin <= 2) {
		sort(range_begin, range_end);
		return;
	}
	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	vector<typename RandomIt::value_type> elements1(begin(elements), (begin(elements)+((elements.size() / 2))));
	vector<typename RandomIt::value_type> elements2((begin(elements)+(elements.size() / 2)), end(elements));
	MergeSort(static_cast<RandomIt>(begin(elements1)), static_cast<RandomIt>(end(elements1)));
	MergeSort(static_cast<RandomIt>(begin(elements2)), static_cast<RandomIt>(end(elements2)));
	merge(elements1.begin(), elements1.end(), elements2.begin(), elements2.end(), range_begin);
}

template<typename RandomIt>
void MergeSort3(RandomIt range_begin, RandomIt range_end) {
	if (range_end - range_begin <= 3) {
		sort(range_begin, range_end);
		return;
	}
	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	vector<typename RandomIt::value_type> elements1(begin(elements), (begin(elements) + ((elements.size() / 3))));
	vector<typename RandomIt::value_type> elements2((begin(elements) + (elements.size() / 3)), (begin(elements) + (2*(elements.size()) / 3)));
	vector<typename RandomIt::value_type> elements3((begin(elements) + (2*(elements.size()) / 3)), end(elements));
	MergeSort3(begin(elements1), end(elements1));
	MergeSort3(begin(elements2), end(elements2));
	MergeSort3(begin(elements3), end(elements3));
	vector<typename RandomIt::value_type> tmp;
	merge(elements1.begin(), elements1.end(), elements2.begin(), elements2.end(), back_inserter(tmp));
	merge(tmp.begin(), tmp.end(), elements3.begin(), elements3.end(), range_begin);
}

int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
	vector<int> g = { 6, 4, 7, 6, 4, 4, 0, 1, 9 };
	MergeSort3(begin(g), end(g));
	for (int x : g) {
		cout << x << " ";
	}
	cout << endl;
    return 0;
}