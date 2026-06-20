#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Compartment {
public:
    virtual string notice() = 0;
};

class FirstClass:public Compartment{
public:
    string notice()override{
        return "Welcome to First Class Compartment";
    }
};

class Ladies:public Compartment{
public:
    string notice()override{
        return "Welcome to Ladies Compartment";
    }
};

class General:public Compartment{
public:
    string notice()override{
        return "Welcome to General Compartment";
    }
};

class Luggage:public Compartment{
public:
    string notice()override{
        return "Welcome to Luggage Compartment";
    }
};

int main() {

    Compartment* arr[10];
    srand(time(0));

    for(int i=0;i<10;i++) {
        int r = rand() % 4 + 1;

        switch(r) {
            case 1:
                arr[i]=new FirstClass();
                break;
            case 2:
                arr[i]=new Ladies();
                break;
            case 3:
                arr[i]=new General();
                break;
            case 4:
                arr[i]=new Luggage();
                break;
        }
    }

    cout << "Compartment Notices:" << endl;
    for(int i=0; i<10;i++)
    cout<<arr[i]->notice()<<endl;

    for(int i=0;i<10;i++)
    delete arr[i];

    return 0;
}