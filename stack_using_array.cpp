#include <iostream>
#define MAX 100
using namespace std;
class Stack
{
private:
    int arr[MAX];
    int topIndex;

public:
    Stack()
    {
        topIndex = -1;
    }
    bool isFull()
    {
        return topIndex == MAX - 1;
    }
    void pushElement(int element)
    {
        if (isFull())
        {
            cout << " the stack is full";
            return;
        }
        arr[++topIndex] = element;
        cout << element  << " Pushed to the stack" << endl;
    }
    int top()
    {
        if (topIndex == -1)
        {
            cout << "the stack is Empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }
    int pop()
    {
        if (topIndex == -1)
        {
            cout << "No item to pop" << endl;
            return -1;
        }
        return arr[topIndex--];
    }
    bool isEmpty()
    {
        return topIndex == -1;
    }
    int size()
    {
        return topIndex + 1;
    }
};

int main()
{
    Stack s; // a) Creation
    int choice, value;

    do
    {
        cout << "\n----- Stack Menu -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Size\n";
        cout << "5. Is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.pushElement(value);
            break;

        case 2:
        {
            int popped = s.pop();
            if (popped != -1)
                cout << "Popped element: " << popped << endl;
            break;
        }

        case 3:
        {
            int t = s.top();
            if (t != -1)
                cout << "Top element: " << t << endl;
            break;
        }

        case 4:
            cout << "Stack size: " << s.size() << endl;
            break;

        case 5:
            cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}