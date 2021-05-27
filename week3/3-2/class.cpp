#include "class.h"
#include <iostream>
using namespace std;

PhoneNumber::PhoneNumber(const string& international_number) {   
    string str = international_number;
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    string emp = str;
    emp.erase(remove(emp.begin(), emp.end(), '+'), emp.end());
    emp.erase(remove(emp.begin(), emp.end(), '-'), emp.end());
    if (!emp.empty()) {
        if (str.find('+') == 0) {  // starts with +

            if ((str.find_first_of('-') !=     // if has 
                str.find_last_of('-')) &&      // at least two -
                (str.find('-', 0) != string::npos)) {
                country_code_ = str.substr(1, str.find_first_of('-') - 1);
                city_code_ = str.substr(str.find_first_of('-') + 1, str.find('-', str.find_first_of('-') + 1) // second inclusion of - sign
                    - str.find_first_of('-') - 1);
                local_number_ = str.substr(str.find('-', str.find_first_of('-') + 1) + 1, str.size());
            }
            else {
                throw invalid_argument("Contanis only country and city code");
            }
        }
        else {
            throw invalid_argument("Starts with no + sign");
        }
    }
    else {
        throw invalid_argument("Empty number");
    }
}
string PhoneNumber::GetCountryCode() const {
    return country_code_;

}
string PhoneNumber::GetCityCode() const {
    return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
    return local_number_;

}
string PhoneNumber::GetInternationalNumber() const {
    return ('+' + this->GetCountryCode() + '-' + this->GetCityCode() + '-' + this->GetLocalNumber());

}