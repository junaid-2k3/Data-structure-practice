#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderNumber;
    int tableNumber;
    string items;
    int priority; // 1 for VIP, 2 for normal, higher = lower priority
    Order* next;
};

class OrderQueue {
private:
    Order* head;

public:
    OrderQueue() {
        head = nullptr;
    }

    // Insert order based on priority
    void addOrder(int orderNum, int tableNum, string itemList, int priorityLevel) {
        Order* newOrder = new Order{orderNum, tableNum, itemList, priorityLevel, nullptr};

        // If list is empty or new order has higher priority than head
        if (!head || priorityLevel < head->priority) {
            newOrder->next = head;
            head = newOrder;
            return;
        }

        // Insert in appropriate position based on priority
        Order* current = head;
        while (current->next && current->next->priority <= priorityLevel) {
            current = current->next;
        }

        newOrder->next = current->next;
        current->next = newOrder;
    }

    // Remove order by order number
    void removeOrder(int orderNum) {
        if (!head) {
            cout << "No orders to remove.\n";
            return;
        }

        if (head->orderNumber == orderNum) {
            Order* temp = head;
            head = head->next;
            delete temp;
            cout << "Order #" << orderNum << " removed.\n";
            return;
        }

        Order* current = head;
        while (current->next && current->next->orderNumber != orderNum) {
            current = current->next;
        }

        if (!current->next) {
            cout << "Order not found.\n";
        } else {
            Order* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Order #" << orderNum << " removed.\n";
        }
    }

    // Modify order (e.g., update items)
    void modifyOrder(int orderNum, string newItems) {
        Order* current = head;
        while (current && current->orderNumber != orderNum) {
            current = current->next;
        }

        if (!current) {
            cout << "Order not found.\n";
        } else {
            current->items = newItems;
            cout << "Order #" << orderNum << " updated.\n";
        }
    }

    // Display all current orders
    void displayOrders() {
        if (!head) {
            cout << "No current orders.\n";
            return;
        }

        Order* current = head;
        cout << "\nCurrent Orders (Priority Queue):\n";
        while (current) {
            cout << "Order #" << current->orderNumber
                 << " | Table: " << current->tableNumber
                 << " | Items: " << current->items
                 << " | Priority: " << current->priority << endl;
            current = current->next;
        }
    }

    // Destructor to free memory
    ~OrderQueue() {
        while (head) {
            Order* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    OrderQueue orders;

    orders.addOrder(101, 5, "Burger, Fries", 2);     // Normal
    orders.addOrder(102, 2, "Steak", 1);             // VIP
    orders.addOrder(103, 7, "Pasta, Coke", 2);
    orders.addOrder(104, 3, "Pizza", 3);             // Lower priority

    orders.displayOrders();

    cout << "\n-- Modifying Order 103 --\n";
    orders.modifyOrder(103, "Pasta, Coke, Salad");

    cout << "\n-- Cancelling Order 101 --\n";
    orders.removeOrder(101);

    orders.displayOrders();

    return 0;
}
