#include <iostream>
#include "stacks&queues.h"

using namespace std;

int main() {
    Queue todoList;      //FIFO: Tasks processed in order
    Stack completedLog;  //LIFO: Most recent finished task is on top
    Stack buffer;        //Temporary storage finished tasks before moving to completedLog
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
                cout << "Enter the ID you just finished to archive it: ";
                cin >> taskId;
                //Copy todoList to buffer by traversing one at a time to find the taskId and push it to buffer without the given taskId
                while (todoList.peek() != -1) {
                    int currentTask = todoList.dequeue();
                    if (currentTask == taskId) {
                        buffer.push(currentTask); //Push the completed task to buffer
                    } else {
                        buffer.push(currentTask); //Push other tasks to buffer temporarily
                    }
                }
                //Now move all tasks back to todoList except the completed one
                while (buffer.peek() != -1) {
                    int tempTask = buffer.pop();
                    if (tempTask != taskId) {
                        todoList.enqueue(tempTask); //Re-enqueue tasks except the completed one
                    }
                }
                completedLog.push(taskId);
                break;

            case 3:
                cout << "Reverting last completed task...\n";
                todoList.enqueue(completedLog.peek()); //Re-enqueue the most recently completed task
                completedLog.pop();
                break;

            case 4:
                todoList.display();
                break;

            case 5:
                completedLog.display();
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