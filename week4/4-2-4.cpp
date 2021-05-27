#include <string>
#include <iostream>
#include <vector>
using namespace std; 

enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;  
	Gender gender;  
	bool is_employed;  
};

void PrintStats(vector<Person> persons) {
	vector<Person> woman;
	vector<Person> man;
	vector<Person> work_woman;
	vector<Person> unwork_woman;
	vector<Person> work_man;
	vector<Person> unwork_man;
	for (const auto& i : persons) {
		if (i.gender == Gender::FEMALE) {
			woman.push_back(i);
			if (i.is_employed == true) {
				work_woman.push_back(i);
			} else {
				unwork_woman.push_back(i);
			}
		} else {
			man.push_back(i);
			if (i.is_employed == true) {
				work_man.push_back(i);
			} else {
				unwork_man.push_back(i);
			}
		}
	}
	cout << "all:" << ComputeMedianAge(persons.begin(), persons.end()) << endl;
	cout << "men:" << ComputeMedianAge(man.begin(), man.end()) << endl;
	cout << "woman:" << ComputeMedianAge(woman.begin(), woman.end()) << endl;
	cout << "employed man :" << ComputeMedianAge(work_man.begin(), work_man.end()) << endl;
	cout << "unemployed man:" << ComputeMedianAge(unwork_man.begin(), unwork_man.end()) << endl;
	cout << "employed woman :" << ComputeMedianAge(work_woman.begin(), work_woman.end()) << endl;
	cout << "unemployed woman:" << ComputeMedianAge(unwork_woman.begin(), unwork_woman.end()) << endl;
}


int main() {
	vector<Person> persons = {
		{31, Gender::MALE, false},
		{40, Gender::FEMALE, true},
		{24, Gender::MALE, true},
		{20, Gender::FEMALE, true},
		{80, Gender::FEMALE, false},
		{78, Gender::MALE, false},
		{10, Gender::FEMALE, false},
		{55, Gender::MALE, true},
	};
	PrintStats(persons);
}