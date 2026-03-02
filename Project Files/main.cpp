#include <iostream>
#include "stacks&queues.h"

int main() {
    Stack stack;
    Queue queue;
    int choice, val;

    do {
        cout << "\n1. Push to Stack\n2. Pop from Stack\n3. Enqueue to Queue\n4. Dequeue from Queue\n5. Display Stack\n6. Display Queue\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                stack.push(val);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Enter value to enqueue: ";
                cin >> val;
                queue.enqueue(val);
                break;
            case 4:
                queue.dequeue();
                break;
            case 5:
                stack.display();
                break;
            case 6:
                queue.display();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}