#include <iostream>

using namespace std;
int data = 1;
void code(){}
int bss;

int main() {

    const int * const rodata = new int(3);

    int stack = 0;
    int * heap = new int[10];

    cout << "code\t" << (void*) code << endl;
    cout << "Rodata\t" << (void*)rodata << endl;
    cout << "data\t" << &data << endl;
    cout << "BSS\t" << &bss << endl;
    cout << "HEAP\t" << heap << endl;
    cout << "Stack\t" << &stack << endl;
}
