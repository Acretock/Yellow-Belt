#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
    auto left = lower_bound(range_begin, range_end, string(prefix));
    auto next = prefix;
    next[next.size()-1]++;
    auto right = lower_bound(range_begin, range_end, string((next)));
    return make_pair(left, right);
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    auto left = lower_bound(range_begin, range_end, string(1, prefix));
    auto right = lower_bound(range_begin, range_end, string(1, (prefix + 1)));
    return make_pair(left, right);
}


int main() {
    const vector<string> sorted_strings = { "moscow", "motovilikha", "vologda" };  
    const  auto m_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    const auto p_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
        (p_result.second - begin(sorted_strings)) << endl;
    const auto z_result =
        FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
        (z_result.second - begin(sorted_strings)) << endl;
    const vector<string> sorted_strings2 = { "moscow", "motovilikha", "murmansk" };
    const auto mo_result =
        FindStartsWith(begin(sorted_strings2), end(sorted_strings2), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    const auto mt_result =
        FindStartsWith(begin(sorted_strings2), end(sorted_strings2), "mt");
    cout << (mt_result.first - begin(sorted_strings2)) << " " <<
        (mt_result.second - begin(sorted_strings2)) << endl;
    const auto na_result =
        FindStartsWith(begin(sorted_strings2), end(sorted_strings2), "na");
    cout << (na_result.first - begin(sorted_strings2)) << " " <<
        (na_result.second - begin(sorted_strings2)) << endl;
    return 0;
}