#include <iostream>
#include <iomanip>
using namespace std;

class InventoryItem {
private:
    int itemNumber;
    int quantity;
    double cost;

public:
    InventoryItem(int itemNum, double itemCost, int qty)
        : itemNumber(itemNum), cost(itemCost), quantity(qty) {}

    double getItemCost() const {
        return cost;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int qty) { ,
        quantity = qty;
    }
};

class CashRegister {
private:
    double profitMargin;

public:
    CashRegister(double profit) : profitMargin(profit) {}

    void processPurchase(InventoryItem& item, int quantity) { ,
        if (quantity < 0) {
            cout << "Error: Quantity cannot be negative." << endl;
            return;
        }

        if (quantity > item.getQuantity()) {
            cout << "Error: Quantity exceeds available inventory." << endl;
            return;
        }

        double unitPrice = item.getItemCost() * (1 + profitMargin);
        double subtotal = unitPrice * quantity;
        double salesTax = subtotal * 0.06;
        double total = subtotal + salesTax;

        cout << fixed << setprecision(2);
        cout << "Purchase Subtotal: $" << subtotal << endl;
        cout << "Sales Tax (6%): $" << salesTax << endl;
        cout << "Total: $" << total << endl;

        item.setQuantity(item.getQuantity() - quantity);
    }
};

int main() {
    InventoryItem item1(101, 10.99, 50);

    CashRegister register1(0.30);

    int quantity;
    cout << "Enter the quantity of item #" << item1.getQuantity() << " being purchased: ";
    cin >> quantity;

    register1.processPurchase(item1, quantity);

    cout << "Remaining quantity of item #" << item1.getQuantity() << ": " << item1.getQuantity() << endl;

    return 0;
}
