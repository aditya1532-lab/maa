#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Function to add a job to the queue
void addJob(queue<string>& jobQueue, const string& job) {
    jobQueue.push(job);  // Enqueue the job into the queue
    cout << "Job \"" << job << "\" added to the queue." << endl;
}

// Function to delete a job from the queue
void deleteJob(queue<string>& jobQueue) {
    if (!jobQueue.empty()) {
        string job = jobQueue.front();  // Get the front job in the queue
        jobQueue.pop();  // Dequeue the job from the queue
        cout << "Job \"" << job << "\" has been processed and removed from the queue." << endl;
    } else {
        cout << "No jobs in the queue to process." << endl;
    }
}

// Function to display the current jobs in the queue
void displayJobs(const queue<string>& jobQueue) {
    if (jobQueue.empty()) {
        cout << "No jobs in the queue." << endl;
        return;
    }

    queue<string> tempQueue = jobQueue;  // Copy the queue to avoid modifying the original queue
    cout << "Current jobs in the queue: ";
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;
}

int main() {
    queue<string> jobQueue;  // Queue to store job names

    int choice;
    string job;
    
    do {
        cout << "\nJob Queue Menu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter job name: ";
                cin.ignore();  // To clear the newline left in the input buffer
                getline(cin, job);  // Read the full job name
                addJob(jobQueue, job);
                break;

            case 2:
                deleteJob(jobQueue);
                break;

            case 3:
                displayJobs(jobQueue);
                break;

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}