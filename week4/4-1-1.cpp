#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    vector<int> res;
    bool flag = true;
    for (auto i : numbers) {
        if (flag) {
            if (i >= 0) {
                res.push_back(i);
            }
            else {
                flag = false;
            }
        }
    }
    reverse(begin(res), end(res));
    for (auto i : res) {
        cout << i << ' ';
    }
}
int main()
{

    PrintVectorPart({ 6, 1, 8, -5, 4 });  
    cout << endl;
    PrintVectorPart({ -6, 1, 8, -5, 4 });  // íè÷åãî íå âûâåäåòñÿ
    cout << endl;
    PrintVectorPart({ 6, 1, 8, 5, 4 });
    cout << endl;
    return 0;
}