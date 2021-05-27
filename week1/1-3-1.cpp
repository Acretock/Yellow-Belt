#include <map>
#include <vector>
#include <iostream>
#include <map>
#include <utility>

using namespace std;


template<typename First, typename Second> 
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2);

template<typename T> 
vector<T> operator*(const vector<T>& v1, const vector<T>& v2);

template<typename First, typename Second> 
map<First, Second> operator*(const map<First, Second>& m1, const map<First, Second>& m2);

template<typename T> 
T Sqr(T t);



template<typename First,typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return make_pair(f, s);
}
template<typename T> 
vector<T> operator*(const vector<T>& v1, const vector<T>& v2) {
    vector<T> res;
    for (int i = 0; i < static_cast<int>(v1.size()); i++) {
        res.push_back(v1[i] * v2[i]);
    }
    return res;
}

template<typename First, typename Second>
map<First, Second> operator*(const map<First, Second>& m1, const map<First, Second>& m2) {
    map<First, Second> res;
        for (const auto& i : m1) {
            First f = i.first;
            Second s = i.second * m2.at(i.first);
            res.insert({ f,s });
        }
    return res;
}

template<typename T>
T Sqr(T t) {
    return t * t;
}

int main()
{
    vector<int> a = { 2,3,4 };
    cout << "vector: ";
    for (auto i: Sqr(a))
        cout << i << ' ';
    cout << endl;
    auto b = make_pair(3, 4);
    auto res = Sqr(b);
    cout << "pair: ";
    cout << res.first << " " << res.second << endl;
    map<int, pair<int, int>> c = {
        {4,{2,2}},
        {7,{4,3}}
    };
    cout << "map of pairs: " << endl;
    for (const auto& x : Sqr(c)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}