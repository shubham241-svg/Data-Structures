/*create a user class with properties :id(private), username(public), and password(private).
its id should be initialized in a parameterized constructor 
it should have getter setter for the password*/

#include <iostream>
#include <string>
using namespace std;

class user{
    string id;
    string password;

    public:
        string username;

        user(string id, string username, string password){
            this->id = id;
            this->username = username;
            this->password = password;
        }

        void setpassword(string pas){
            password = pas ;

        }

        string getpassword(){
            return password;
        }




};

int main(){
    user u1("s12084", "shub_cool", "SH@241192");
    cout<< u1.getpassword();
}

