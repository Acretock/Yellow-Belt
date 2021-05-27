#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

enum class Lang {
	DE,FR,IT
};

struct Region
{
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

const bool  operator==(const Region& rhs, const Region& lhs) {
	return tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population) ==
		tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
	if (regions.size() == 0) {	//if empty, return 0
		return 0;
	}
	vector<int> count;	// number of encounters for each element									
	for (int i = 0; i < static_cast<int>(regions.size()); i++) {
		count.push_back(1);	
		for (int j = i+1; j < static_cast<int>(regions.size()); j++) {
			if (regions[i] == regions[j]) {
				count[i]++;
				}
		}
	}
	int max = 1;
	for (auto k : count) {	//finding max encounters
		if (max < k) {
			max = k;
		}
	}
	return max;
	
}

int main()
{
	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
			{ {Lang::DE,"Moskau"},{Lang::FR,"Moscou"},{Lang::IT,"Mosca"}},
			89
		},
		{
			"Russia",
			"Eurasia",
			{ {Lang::DE,"Moskau"},{Lang::FR,"Moscou"},{Lang::IT,"Mosca"}},
			89
		},
		{
			"Moscow",
			"Russia",
			{ {Lang::DE,"Moskau"},{Lang::FR,"Moscou"},{Lang::IT,"Mosca"}},
			89
		},
		{
			"Moscow",
			"Russia",
			{ {Lang::DE,"Moskau"},{Lang::FR,"Moscou"},{Lang::IT,"Mosca"}},
			89
		},
		{
			"Russia",
			"Eurasia",
			{ {Lang::DE,"Moskau"},{Lang::FR,"Moscou"},{Lang::IT,"Mosca"}},
			89
		}
		}) << endl;
	cout << FindMaxRepetitionCount({
		{
			"Moscow",
			"Russia",
			{ {Lang::DE,"Moskau"},{Lang::FR,"Moscou"},{Lang::IT,"Mosca"}},
			89
		},
		{
			"Russia",
			"Eurasia",
			{ {Lang::DE,"Moskau"},{Lang::FR,"Moscou"},{Lang::IT,"Mosca"}},
			89
		},		
		}) << endl;
	cout << FindMaxRepetitionCount({});

    return 0;
}