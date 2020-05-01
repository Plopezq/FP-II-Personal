#include <iostream>
using namespace std;

int main() {
    double a = 1.5;
    double* p1, * p2, * p3;
    p1 = &a;
    p2 = new double;
    *p2 = *p1;
    p3 = new double;
    *p3 = 123.45;
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    delete p2;
    delete p3;

    return 0;
}