#include <iostream>
using namespace std;

class Population {
private:
    int population;
    int births;
    int deaths;

public:
    Population(int pop, int b, int d) {
        if (pop < 1 || b < 0 || d < 0) {
            cerr << "Error: Population, births, and deaths must be positive integers." << endl;
            population = 0;
            births = 0;
            deaths = 0;
        } else {
            population = pop;
            births = b;
            deaths = d;
        }
    }

    double calculateBirthRate() const {
        return static_cast<double>(births) / population;
    }

    double calculateDeathRate() const {
        return static_cast<double>(deaths) / population;
    }
};

int main() {
    int pop, b, d;
    cout << "Enter the population: ";
    cin >> pop;
    cout << "Enter the number of births: ";
    cin >> b;
    cout << "Enter the number of deaths: ";
    cin >> d;

    Population p(pop, b, d);

    cout << "Birth rate: " << p.calculateBirthRate() << endl;
    cout << "Death rate: " << p.calculateDeathRate() << endl;

    return 0;
}

