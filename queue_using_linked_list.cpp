#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
    Node *frontNode;
    Node *rearNode;
    int count;

public:
    Queue()
    {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    ~Queue()
    {
        while (!isEmpty())
            dequeue();
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            frontNode = newNode;
            rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
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
        Node *temp = frontNode;
        int value = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr)
            rearNode = nullptr;
        delete temp;
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
        return frontNode->data;
    }

    int rear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No rear element." << endl;
            return -1;
        }
        return rearNode->data;
    }

    bool isEmpty()
    {
        return frontNode == nullptr;
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