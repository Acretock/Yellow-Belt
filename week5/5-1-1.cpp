#include <string>
#include <iostream>

using namespace std;

class Animal {

protected:
    string Name;
};
class Dog : public Animal {
public:
    Dog(string name);
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};
Dog::Dog(string dog) {
    Name = dog;
}
