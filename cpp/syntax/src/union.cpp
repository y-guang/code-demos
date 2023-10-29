#include <iostream>

using namespace std;

union BasicTypesUnion {
    int    i;
    double d;
};

struct SimpleStruct {
    double d;
    char   c;
};

union UnionWithStruct {
    SimpleStruct s;
    int          i;
};

void basic_types() {
    // the size is the size of the largest member
    cout << "union with basic types" << endl;
    BasicTypesUnion u;
    cout << "size: " << sizeof(u) << endl;
    u.i = 1;
    cout << "u.i = 1" << endl;
    cout << "\tu.i: " << u.i << endl;
    cout << "\tu.d: " << u.d << endl;
    cout << endl;
}

void union_with_struct() {
    // struct work as the same as basic types
    cout << "union with struct" << endl;
    UnionWithStruct u;
    cout << "size: " << sizeof(u) << endl;
    u.i = 1;
    u.s.d = 1.0;
    u.s.c = 'a';
    cout << "u.i = 1" << endl;
    cout << "u.s.d = 1.0" << endl;
    cout << "u.s.c = 'a'" << endl;
    cout << "\tu.s.d: " << u.s.d << endl;
    cout << "\tu.s.c: " << u.s.c << endl;
    cout << "\tu.i: " << u.i << endl;
    cout << endl;
}

int main(int argc, char const *argv[]) {
    basic_types();
    union_with_struct();
    return 0;
}