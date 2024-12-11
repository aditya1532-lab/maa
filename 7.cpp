#include <iostream>
#include <string>
using namespace std;

// Define the structure for a single node
struct Node {
    string name;    // Name of the student
    string prn;     // PRN of the student
    Node* next;     // Pointer to the next node
};

// Define the PinnacleClub class to manage the linked list
class PinnacleClub {
private:
    Node* head;    // Head of the linked list (will be the president node)
    Node* tail;    // Tail of the linked list (will be the secretary node)

public:
    // Constructor to initialize an empty club with no members
    PinnacleClub() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to add a new member as a club member
    void addMember(const string& prn, const string& name) {
        Node* newNode = new Node();
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) {  // If no members, make the new node president and secretary
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;  // Add new member at the end
            tail = newNode;        // Update tail to the new member
        }
    }

    // Function to add the president node (Only works if the club is empty)
    void addPresident(const string& prn, const string& name) {
        if (head == nullptr) {
            head = new Node();
            head->prn = prn;
            head->name = name;
            head->next = nullptr;
            tail = head;
            cout << "President added to the club." << endl;
        } else {
            cout << "President already exists!" << endl;
        }
    }

    // Function to delete the president node (Only works if there are other members)
    void deletePresident() {
        if (head == nullptr) {
            cout << "No president to delete." << endl;
        } else if (head == tail) {
            cout << "The club cannot exist without a president. Please add members first." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "President has been deleted." << endl;
        }
    }

    // Function to display the members of the club
    void displayMembers() {
        if (head == nullptr) {
            cout << "No members in the club." << endl;
            return;
        }
        Node* temp = head;
        cout << "\nClub Members:" << endl;
        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~PinnacleClub() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Main function to demonstrate the functionality
int main() {
    PinnacleClub club;

    // Add president (works only if the club is empty)
    string presidentPrn, presidentName;
    cout << "Enter President PRN: ";
    cin >> presidentPrn;
    cout << "Enter President Name: ";
    cin.ignore();  // To ignore the leftover newline
    getline(cin, presidentName);
    club.addPresident(presidentPrn, presidentName);

    // Add members to the club
    string prn, name;
    char choice;
    do {
        cout << "Enter member PRN: ";
        cin >> prn;
        cout << "Enter member Name: ";
        cin.ignore();  // To ignore the leftover newline
        getline(cin, name);
        club.addMember(prn, name);
        
        cout << "Do you want to add another member? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Display all members
    club.displayMembers();

    // Delete the president
    cout << "Do you want to delete the president? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        club.deletePresident();
    }

    // Display members after deleting the president
    club.displayMembers();

    return 0;
}