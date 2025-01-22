#include <iostream>
#include <string>
using namespace std;

// compile time polymorphism


// 1) function overloading 

class print{
    public :
        void show(int x){
            cout<< "int: " << x << endl;
        }

        void show(string str){
            cout<<"string : "<<str << endl;
        }

};
// 2) operator overloading 
class Complex{
    int real ;
    int img;

    public:
        Complex(int r, int i ){
            real = r; 
            img = i;

        }

        void shownum(){
            cout<< real << " + " << img << "i \n";

        }

        //operator overloading

        Complex operator + (Complex &c2){
            int resReal = this->real + c2.real;
            int resImg = this->img + c2.img;
            Complex c3(resReal, resImg);
            return c3;

        }

        Complex operator - (Complex &obj){
            int resReal = this->real - obj.real;
            int resImg = this->img - obj.img;
            Complex res(resReal, resImg);
            return res;
        }
};


// Runtime polymorphism
// 1) function overiding 


class parent{
    public:
        void show(){
            cout<< "parent class .. \n";
        }

        virtual void hello(){
            cout << "hello parent \n";
        }
};

class child : public parent{
    public :
        void show(){
            cout<< " child class ... \n";
        }

        void hello(){
            cout << "hello child clss \n";
        }
};


int main(){

    //operator overloading 

    // print obj1;
    // obj1.show(3);
    // obj1.show("three eyed arven");

    // Complex c1(2,3);
    // Complex c2(3,6);

    // Complex c3 = c1 + c2;
    // c3.shownum();

    child c1;
    c1.show();

    return 0;
}