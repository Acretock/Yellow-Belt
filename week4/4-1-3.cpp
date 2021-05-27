#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    string str =s;
    vector<string> words;
    while ((str.find(' ') + 1) != 0) {
        words.push_back(str.substr(0, str.find(' ')));
        str = str.substr(str.find(' ')+1);
    }
    words.push_back(str);
    return words;
}

int main() {
    string s = "C Cpp Java Python";
    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;
}