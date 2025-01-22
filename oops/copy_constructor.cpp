#include <iostream>
#include <string>
using namespace std;

class Car{
    public:
        string name;
        string color;
        int *mileage;

        Car(string name, string color){
            this->name = name;
            this->color = color;
            mileage = new int; // Dynamic allocation
            *mileage = 12;
        }

        // Corrected Copy Constructor
        Car(const Car &original){
            cout << "Copying original to new...\n";
            name = original.name;
            color = original.color;
            mileage = new int; // Allocate new memory
            *mileage = *(original.mileage); // Copy the value
        }

        // Destructor to free dynamically allocated memory
        ~Car(){
            cout<< "deleting the oobject";
            delete mileage;
        }
};

int main(){
    Car c1("maruti 800", "white");
    Car c2(c1);

    cout << c2.name << endl;
    cout << c2.color << endl;

    *c2.mileage = 10; // Note the use of * to dereference

    cout << *c1.mileage << endl; // Will still be 12
    cout << *c2.mileage << endl; // Will be 10

    return 0;
}
