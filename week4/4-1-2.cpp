#include <set>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
vector<T> FindGreaterElements(const set<T>& set, const T& border) {
    return vector<T>(set.upper_bound(border), end(set));
}
 
int main() {
    for (int x : FindGreaterElements(set<int>{1,5,6}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}