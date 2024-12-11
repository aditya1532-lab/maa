#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    string *queue;  // Array to store orders
    int front, rear, size, capacity;

public:
    // Constructor to initialize the queue with capacity M
    CircularQueue(int M) {
        capacity = M;
        queue = new string[capacity];
        front = rear = -1;
        size = 0;
    }

    // Destructor to clean up dynamically allocated memory
    ~CircularQueue() {
        delete[] queue;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Add an order to the queue (enqueue)
    void addOrder(const string& order) {
        if (isFull()) {
            cout << "Queue is full. Cannot accept more orders.\n";
        } else {
            if (front == -1) {  // First order
                front = 0;
            }
            rear = (rear + 1) % capacity;  // Circular increment
            queue[rear] = order;
            size++;
            cout << "Order added: " << order << endl;
        }
    }

    // Serve an order (dequeue)
    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
        } else {
            cout << "Order served: " << queue[front] << endl;
            front = (front + 1) % capacity;  // Circular increment
            size--;
            if (size == 0) {  // Reset pointers when the queue is empty
                front = rear = -1;
            }
        }
    }

    // Display all orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
        } else {
            cout << "Current orders in the queue: ";
            int i = front;
            for (int count = 0; count < size; count++) {
                cout << queue[i] << " ";
                i = (i + 1) % capacity;  // Circular increment
            }
            cout << endl;
        }
    }
};

int main() {
    int M;  // Maximum number of orders the parlor can accept
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    CircularQueue pizzaParlor(M);

    int choice;
    string order;

    do {
        cout << "\nPizza Parlor Menu:\n";
        cout << "1. Add Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                if (!pizzaParlor.isFull()) {
                    cout << "Enter order details: ";
                    cin.ignore();  // To clear the newline left in the input buffer
                    getline(cin, order);  // Read the full order description
                    pizzaParlor.addOrder(order);
                } else {
                    cout << "The pizza parlor is full, cannot accept new orders.\n";
                }
                break;

            case 2:
                pizzaParlor.serveOrder();
                break;

            case 3:
                pizzaParlor.displayOrders();
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
Explan