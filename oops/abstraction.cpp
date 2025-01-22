#include <iostream>
#include <string>
using namespace std;



// abstract class
class shape{
    public :
        virtual void draw() = 0; // abstract function , pure virtual function 
};

class circle: public shape{
    public :
        void draw(){
            cout<< "drawing circle .. \n";
        }};

class square : public shape{
    public :
        void draw(){
            cout<< "drawing a square";
        }
};


int main(){


    circle c1;
    c1.draw();

    square c2;
    c2.draw();

    
    return 0;
}
