#include <iostream>
#include <string>
using namespace std;


class Animal{
    public :
        string color;

        void eat(){
            cout<< "eats\n";
        }

        void breathe(){
            cout<< "breathe\n";
        }
};

//single inheritance
/*class Fish : public Animal {
    public:

        int fins;
        void swim(){
            eat();
            cout<< "swims\n";

        }

    
};
*/


// multilevel inheritance

class Mammal: public Animal{
    public:
        string bloodtype;

        Mammal(){
            bloodtype = "warm";
        }
};


class Dog : public Mammal{
    public :
        void tailwag(){
            cout<< "a Dog wags its tail\n";
        }

};

// Hiearchial inheritance dog and human both inherit from same base class 

class human: public Mammal{
    public :
        void dsa(){
            cout << "gotta learn this shit\n";
        }
};

int main(){
    Dog d1;
    d1.tailwag();
    cout<< d1.bloodtype;
    d1.eat();

    human h1;
    h1.dsa();
    cout<< h1.bloodtype;

    return 0;
}

// this overall code is following multiple types of inheritance so it can be said it is hybrid inheritance
