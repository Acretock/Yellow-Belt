#include <iostream>
#include "class.h"
using namespace std;

int main()
{
	PhoneNumber b{ "+7 - 495 - 111 - 22 - 33" };
	PhoneNumber c{ "+7 - 495 - 1112233" };
	PhoneNumber d{ "+1 - 1 - 1" };
	PhoneNumber e{ "+1 - 2 - coursera - cpp" };
	cout << b.GetInternationalNumber() << endl << c.GetInternationalNumber() << endl << d.GetInternationalNumber() << endl << e.GetInternationalNumber() << endl;
	try {
		PhoneNumber a{ "1-2-333" };		
	}
	catch (exception& e) {
		cout << e.what() << endl; try {
			PhoneNumber a{ "+7-1233" };
		}
		catch (exception& e) {
			cout << e.what() << endl; try {
				PhoneNumber a{ "+  - - " };
			}
			catch (exception& e) {
				cout << e.what();
			}
		}
		}
		
}