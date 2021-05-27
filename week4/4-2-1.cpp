#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
    for (int i=0;i<elements.size();i++) {
        for (int j = i+1 ; j < elements.size(); ++j) {
            if (elements[i] == elements[j]) {
                auto it = begin(elements) + j;
                elements.erase(it);
                j--;    // go back 1 because we deleted an element
            }
        }
    }
}

int main() {
    vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}