#include <set>
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    int min_dist = numeric_limits<int>::max();
    auto elem_number = numbers.begin();
    for (const auto& i : numbers) {
        if (abs(i - border) < min_dist) {   // if distance is smaller
            min_dist = abs(i - border);     // change it
            elem_number = numbers.find(i);  // and remember an element
        }
    }
    return elem_number;
}

int main() {
    set<int> numbers = { 1, 4, 6 };
    cout <<
        *FindNearestElement(numbers, 0) << " " <<
        *FindNearestElement(numbers, 3) << " " <<
        *FindNearestElement(numbers, 5) << " " <<
        *FindNearestElement(numbers, 6) << " " <<
        *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}