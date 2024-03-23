#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Coin {
private:
    string sideUp;

public:
    Coin() {
        srand(time(0));
        int randomValue = rand() % 2;
        sideUp = (randomValue == 0) ? "heads" : "tails";
    }

    void toss() {
        int randomValue = rand() % 2;
        sideUp = (randomValue == 0) ? "heads" : "tails";
    }

    string getSideUp() const {
        return sideUp;
    }
};

int main() {
    Coin myCoin;
    cout << "Initial side facing up: " << myCoin.getSideUp() << endl;

    int headsCount = 0, tailsCount = 0;
    for (int i = 0; i < 20; ++i) {
        myCoin.toss();
        cout << "After toss " << i + 1 << ": " << myCoin.getSideUp() << endl;
        if (myCoin.getSideUp() == "heads")
            headsCount++;
        else
            tailsCount++;
    }

    cout << "Number of times heads appeared: " << headsCount << endl;
    cout << "Number of times tails appeared: " << tailsCount << endl;

    Coin quarter, dime, nickel;
    double balance = 0.0;

    while (balance < 1.0) {
        quarter.toss();
        dime.toss();
        nickel.toss();

        if (quarter.getSideUp() == "heads")
            balance += 0.25;
        if (dime.getSideUp() == "heads")
            balance += 0.10;
        if (nickel.getSideUp() == "heads")
            balance += 0.05;
    }

    cout << "Your balance: $" << balance << endl;
    if (balance == 1.0)
        cout << "Congratulations! You win the game." << endl;
    else
        cout << "Sorry, you lose the game." << endl;

    return 0;
}
