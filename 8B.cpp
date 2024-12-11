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

    // Function to check if a student is present in the set
    bool contains(const string& name) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->name == name) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to find the symmetric difference between this set and another set
    StudentSet symmetricDifference(const StudentSet& otherSet) {
        StudentSet resultSet;

        // Students in set A but not in set B
        Node* tempA = head;
        while (tempA != nullptr) {
            if (!otherSet.contains(tempA->name)) {
                resultSet.addStudent(tempA->name);
            }
            tempA = tempA->next;
        }

        // Students in set B but not in set A
        Node* tempB = otherSet.head;
        while (tempB != nullptr) {
            if (!contains(tempB->name)) {
                resultSet.addStudent(tempB->name);
            }
            tempB = tempB->next;
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

    // Find and display the symmetric difference (students who like either Vanilla or Butterscotch, but not both)
    StudentSet symmetricDiffSet = setA.symmetricDifference(setB);

    cout << "\nStudents who like either Vanilla or Butterscotch, but not both:" << endl;
    symmetricDiffSet.displaySet();

    return 0;