#include <iostream>

using namespace std;

int add_two(int a, int b) {
    return a + b;
}

double add_two(double a, double b) {
    return a + b;
}

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;
    cout << add_two(a, b) << endl;

    double c = 1.1;
    double d = 2.2;
    cout << add_two(c, d) << endl;

    return 0;
}