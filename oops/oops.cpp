#include <iostream>
#include <string>
using namespace std;

class student{
    string name;
    float cgpa;// private properties

public:

    student(string namevalue, float cgpaval){
        cout<< "new student has been created"<<endl;
        name = namevalue; 
        cgpa = cgpaval;
    }
    void setname(string nameval){
        name = nameval;
    }

    string getname(){
        return name;
    }

};

int main(){
    student s1("ashok", 8.98);
    cout << s1.getname();
   
    return 0;
}