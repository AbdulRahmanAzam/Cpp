// #include <iostream>
// #include <string>
// using namespace std;

#include <iostream>
#include <stdexcept>
using namespace std;

class JumpingCastle {
private:
    int peopleCount;

public:
    JumpingCastle() : peopleCount(0) {}

    void enter() {
        if (peopleCount >= 10) {
            throw overflow_error("Count Overflow");
        }
        peopleCount++;
    }

    void exit() {
        if (peopleCount <= 0) {
            throw underflow_error("Count Underflow");
        }
        peopleCount--;
    }

    int getCurrentCount() const {
        return peopleCount;
    }
};

int main() {
    JumpingCastle jumpingCastle;

    while (true) {
        char choice;
        cout << "Enter 'e' to add a person, 'x' to remove a person: ";
        cin >> choice;

        try {
            if (choice == 'e') {
                jumpingCastle.enter();
                cout << "Person entered. Current count: " << jumpingCastle.getCurrentCount() << endl;
            } else if (choice == 'x') {
                jumpingCastle.exit();
                cout << "Person exited. Current count: " << jumpingCastle.getCurrentCount() << endl;
            } else {
                cout << "Invalid choice. Please enter 'e' or 'x'." << endl;
            }
        } catch (const overflow_error& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const underflow_error& e){
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
   
