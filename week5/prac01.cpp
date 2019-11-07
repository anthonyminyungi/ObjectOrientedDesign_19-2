#include <iostream>

using namespace std;

class A {
    public:
	virtual void print(){
	    cout << "This class is A" << endl;
	}
};

class B : public A{
    public:
	void print(){
	    cout << "This class is B" <<endl;
	}
};

int main(){
    A * a = new B();
    B * b = new B();

    a->print();
    b->print();
    return 0;
}
