#include <iostream>
#include <string>
using namespace std;

class Example {
    public:
        Example(){
            cout << "constructor .. \n";
        }

        ~Example(){
            cout << "destructor .. " << endl;

        }
};


int main() {
    int a = 0 ;
    if(a==0){
        static Example eg1;  // static object it exists in the memory until the very end of the code
    }

    cout << "code ending  .. \n";
    return 0;
}