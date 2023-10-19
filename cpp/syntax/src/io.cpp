#include <iostream>

using namespace std;

void basic_out() {
    int age = 10;
    cout << "Hi, my age is " << age << endl;
}

void basic_in() {
    cout << "input numbuers split by space:" << endl;

    int i;
    int sum = 0;
    while (cin >> i) {
        sum += i;
        // check and consume spaces
        while (cin.peek() == ' ') {
            cin.get();
        }
        if (cin.peek() == '\n') {
            cin.get();
            break;
        }
    }

    cout << "the sum is " << sum << endl;
}

void io_fail_handle() {
    // ignore the remaining input of the last input
    char ch;
    if (cin.fail()) {
        cin.clear();
        while (cin.get(ch) && ch != '\n' && !cin.eof())
            ;
    }
    cout << "input numbuers split by space or non-number:" << endl;

    int i, sum;
    sum = 0;

    cin.clear();
    while (true) {
        if (cin >> i) {
            sum += i;
        } else if (cin.fail()) {
            cin.clear();    // clean all flags
            cin.ignore(1);  // ignore one char
        }

        // check and consume spaces
        while (cin.peek() == ' ') {
            cin.get();
        }
        if (cin.peek() == '\n') {
            cin.get();
            break;
        }
    }

    cout << "the sum is " << sum << endl;
}

int main(int argc, char const *argv[]) {
    basic_out();
    basic_in();
    io_fail_handle();
    return 0;
}
