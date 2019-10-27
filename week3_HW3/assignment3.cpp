#include <iostream>

using namespace std;

int main(){
    char target[] = "Min Yungi";
    long b[267];
    int a = 17;
    int i = 2167;
    int *c = new int[302];
    char * copy = "is no no";
    char name = 'a';
    cout << &name+i << endl;  

    std::cout << (void *)target << '\n';
 
    std::cout << &b << '\n';
 
    std::cout << &a << '\n';

    std::cout << &i << '\n';

    std::cout << (void*) &c << '\n';

    std::cout << (void *) &copy << '\n';

    std::cout << (void *) &name << '\n';

    std::cout << &name + i << '\n';
}
