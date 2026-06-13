#include <iostream>
using namespace std;

// Interface
class Playable {
public:
    virtual void play() = 0;
};

// Veena Class
class Veena : public Playable {
public:
    void play() override {
        cout << "Playing Veena" << endl;
    }
};

// Saxophone Class
class Saxophone : public Playable {
public:
    void play() override {
        cout << "Playing Saxophone" << endl;
    }
};

int main() {

    Veena v;
    v.play();

    Saxophone s;
    s.play();

    Playable* p;

    p = &v;
    p->play();

    p = &s;
    p->play();

    return 0;
}