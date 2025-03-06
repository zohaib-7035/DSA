#include <iostream>
#include <memory> // Include the memory header for unique_ptr

using namespace std;

class User {
public:
    User() {
        cout << "The user is created " << endl;
    }
    ~User() {
        cout << "The user is destroyed" << endl;
    }
    void test_the_function() {
        cout << "I am testing the function" << endl;
    }
};



int main() {
   {
    // Use custom make_unique function to create a unique_ptr
   unique_ptr<User> ali = make_unique<User>();
   //unique_ptr<User> asghar =ali; it is not allowed in this as it is unique so we cannot make the copy

    // Use the unique_ptr to call a method on the User object
    ali->test_the_function();
    cout<<endl;
    
}
    // The unique_ptr will automatically destroy the User object when it goes out of scope
//  it cannot be shared as it is unique
cout<<"it is destroyed here "<<endl<<endl;
// the shared pointer 
{
shared_ptr<User>asad=make_shared<User>();
cout<<endl;
shared_ptr<User>akbar=asad;
cout<<endl;
//here we can make the copy of this as it is shared 
asad->test_the_function();
cout<<endl<<endl;
}
cout<<endl<<endl;
cout<<"The end of the shared shared_ptr"<<endl<<endl;
{
    
shared_ptr<User>a=make_shared<User>();
cout<<endl<<endl<<endl;
cout<<"..........."<<endl;
weak_ptr<User>akbar=a;
cout<<"..........."<<endl;
cout<<endl;

a->test_the_function();
}






    return 0;
}
