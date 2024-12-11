#include <iostream>
#include <string>
using namespace std;

// Node structure for a singly linked list
struct Node {
    string name;    // Name of the student
    Node* next;     // Pointer to the next node
};

// Class to represent a Set of students using a linked list
class StudentSet {
private:
    Node* head;  // Head of the linked list

public:
    // Constructor to initialize an empty set
    StudentSet() {
        head = nullptr;
    }

    // Function to add a student to the set
    void addStudent(const string& name) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = head;
        head = newNode;
    }

    // Function to display the set of students
    void displaySet() {
        if (head == nullptr) {
            cout << "No students in the set." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << endl;
            temp = temp->next;
        }
    }

    // Function to find the intersection of two sets (students who like both)
    StudentSet intersection(const StudentSet& otherSet) {
        StudentSet resultSet;
        Node* temp1 = head;
        
        // Traverse the first set and check if each student exists in the second set
        while (temp1 != nullptr) {
            Node* temp2 = otherSet.head;
            while (temp2 != nullptr) {
                if (temp1->name == temp2->name) {
                    resultSet.addStudent(temp1->name);  // Add to result if found in both sets
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return resultSet;
    }

    // Destructor to clean up dynamically allocated memory
    ~StudentSet() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    StudentSet setA, setB;

    // Add students who like Vanilla Ice Cream (Set A)
    setA.addStudent("Alice");
    setA.addStudent("Bob");
    setA.addStudent("Charlie");

    // Add students who like Butterscotch Ice Cream (Set B)
    setB.addStudent("Bob");
    setB.addStudent("Charlie");
    setB.addStudent("David");

    // Display both sets
    cout << "Students who like Vanilla Ice Cream (Set A):" << endl;
    setA.displaySet();

    cout << "\nStudents who like Butterscotch Ice Cream (Set B):" << endl;
    setB.displaySet();

    // Find and display the intersection (students who like both)
    StudentSet intersectionSet = setA.intersection(setB);

    cout << "\nStudents who like both Vanilla and Butterscotch Ice Cream:" << endl;
    intersectionSet.displaySet();

    return 0;
}