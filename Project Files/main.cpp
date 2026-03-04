#include <iostream>
#include "stacks&queues.h"

using namespace std;

int main() {
    Queue todoList;      // FIFO: Tasks processed in order
    Stack completedLog;  // LIFO: Most recent finished task is on top
    int choice, taskId;

    cout << "=== Productivity Task Manager ===\n";

    do {
        cout << "\n1. Add New Task (Enqueue)"
             << "\n2. Finish Current Task (Dequeue & Push to History)"
             << "\n3. Undo Last Completion (Pop from History)"
             << "\n4. View Active Tasks (Display Queue)"
             << "\n5. View Completed Log (Display Stack)"
             << "\n6. Exit\n";
        cout << "Selection: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Task ID Number: ";
                cin >> taskId;
                todoList.enqueue(taskId); //
                break;

            case 2:
                // Simulation: In a real app, we'd pass the value from Queue to Stack
                cout << "Completing oldest task...\n";
                todoList.dequeue(); //
                cout << "Enter the ID you just finished to archive it: ";
                cin >> taskId;
                completedLog.push(taskId); //
                break;

            case 3:
                cout << "Reverting last completed task...\n";
                completedLog.pop(); //
                break;

            case 4:
                todoList.display(); //
                break;

            case 5:
                completedLog.display(); //
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}