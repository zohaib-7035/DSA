#include<iostream>
using namespace std;

template<class T>
void my_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    cout << "The a=" << a << endl << "The b=" << b << endl;
}

int main() {
    int a = 2;
    int b = 4;
    my_swap(a, b);
    return 0;
}
