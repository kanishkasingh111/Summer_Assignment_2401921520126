#include <iostream>
using namespace std;

class Outer {
public:
    void display() {
        cout << "Display function of Outer Class" << endl;
    }

    class Inner {
    public:
        void display() {
            cout << "Display function of Inner Class" << endl;
        }
    };
};

int main() {
    Outer o;
    o.display();

    Outer::Inner i;
    i.display();

    return 0;
}