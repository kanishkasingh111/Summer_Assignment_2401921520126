#include <iostream>
using namespace std;

// Interface
class Test {
public:
    virtual int square(int n) = 0;
};

// Arithmetic Class
class Arithmetic : public Test {
public:
    int square(int n) override {
        return n * n;
    }
};

// ToTestInt Class
class ToTestInt {
public:
    void displaySquare(int n) {
        Arithmetic a;
        cout << "Square of " << n << " = " << a.square(n) << endl;
    }
};

int main() {
    ToTestInt obj;
    obj.displaySquare(5);

    return 0;
}