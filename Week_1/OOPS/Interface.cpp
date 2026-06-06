#include <iostream>
#include <string>
using namespace std;

// Interface
class LibraryUser {
public:
    int age;
    string bookType;

    virtual void registerAccount() = 0;
    virtual void requestBook() = 0;
};

// KidUsers Class
class KidUsers : public LibraryUser {
public:
    void registerAccount() override {
        if (age < 12) {
            cout << "You have successfully registered under a Kids Account" << endl;
        } else {
            cout << "Sorry, Age must be less than 12 to register as a kid" << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Kids") {
            cout << "Book Issued successfully, please return the book within 10 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only kids books" << endl;
        }
    }
};

// AdultUser Class
class AdultUser : public LibraryUser {
public:
    void registerAccount() override {
        if (age > 12) {
            cout << "You have successfully registered under an Adult Account" << endl;
        } else {
            cout << "Sorry, Age must be greater than 12 to register as an adult" << endl;
        }
    }

    void requestBook() override {
        if (bookType == "Fiction") {
            cout << "Book Issued successfully, please return the book within 7 days" << endl;
        } else {
            cout << "Oops, you are allowed to take only adult Fiction books" << endl;
        }
    }
};

int main() {

    KidUsers kid1;
    kid1.age = 10;
    kid1.bookType = "Kids";

    kid1.registerAccount();
    kid1.requestBook();

    cout << endl;

    KidUsers kid2;
    kid2.age = 18;
    kid2.bookType = "Fiction";

    kid2.registerAccount();
    kid2.requestBook();

    cout<< endl;

    AdultUser adult1;
    adult1.age = 5;
    adult1.bookType = "Kids";

    adult1.registerAccount();
    adult1.requestBook();

    cout<< endl;

    AdultUser adult2;
    adult2.age = 23;
    adult2.bookType = "Fiction";

    adult2.registerAccount();
    adult2.requestBook();

    return 0;
}
