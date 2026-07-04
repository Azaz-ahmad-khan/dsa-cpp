#include <iostream>
using namespace std;

#define MAX 100

class Queue
{
    int arr[MAX];
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue()
    {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isFull()
    {
        return count == MAX;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % MAX;
        arr[rearIndex] = value;
        count++;
        cout << value << " enqueued to queue." << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return -1;
        }
        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % MAX;
        count--;
        return value;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    int rear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No rear element." << endl;
            return -1;
        }
        return arr[rearIndex];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;
    cout << "Size: " << q.size() << endl;

    int dequeued = q.dequeue();
    cout << "Dequeued element: " << dequeued << endl;

    cout << "Front element after dequeue: " << q.front() << endl;
    cout << "Rear element after dequeue: " << q.rear() << endl;
    cout << "Size after dequeue: " << q.size() << endl;
    cout << "Is empty: " << (q.isEmpty() ? "true" : "false") << endl;

    return 0;
}