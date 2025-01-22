#include <iostream>
#include <string>
using namespace std;


// 2nd question

class BankAccount{
    int accountNumber;
    int balance ; 
    

    public :

        BankAccount(int accnum, double bal){
            accountNumber = accnum;
            balance = bal;

        }
        int amount;
        void deposit(int amount){
             balance += amount; 
        }

        void withdraw(int amount){
            if(amount <= balance ){
             balance -= amount ;}

             else{
                cout<< "insufficient balance ;\n";
             }
        }

        int getBalance(){
            return balance;
        }


};


// 1st question done in polymorphism

// 3rd question

class Person{
    protected:
        string name;
        int age;

    public :
        Person(string n, int a){
            name = n;
            age = a;

        }

};

class Student : public Person {
    private :
        string studentID;

    public:
        Student (string n , int a, string id): Person(n, a){
            studentID = id;
        }

        void displayinfo(){
            cout << " name : "<< this->name << endl;
            cout << "age : " << this->age << endl;
            cout << "student id : " << this->studentID << endl;
                    }
};