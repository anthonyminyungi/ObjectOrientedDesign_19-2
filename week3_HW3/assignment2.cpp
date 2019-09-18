#include <iostream>

using namespace std;

int main(){
    char * a = "ABC";
    char b[] = "ABC";

//    b[0] = 'b';
    a[0] = 'b';
    cout << a << endl;
    cout << b << endl;
}
