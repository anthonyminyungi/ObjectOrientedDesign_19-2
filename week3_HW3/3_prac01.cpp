#include <iostream>
using namespace std;

class A{
public:
    int a;
};


A& f(int b){
    A a;
    a.a = b;
    return a;
}

int main() {
    A& a = f(10);
    cout << a.a << endl;
    cout << "Hello world" << endl;
    cout << a.a << endl;
}
