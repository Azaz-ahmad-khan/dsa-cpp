#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nextNode;

    Node(int d)
    {
        data = d;
        nextNode = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    // a) Insert at start
    void push_front(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->nextNode = head;
            head = newNode;
        }
    }

    // b) Insert at end
    void push_back(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->nextNode = newNode;
            tail = newNode;
        }
    }

    // c) Insert at nth position
    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position\n";
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->nextNode;
        }

        if (temp == NULL)
        {
            cout << "Position out of range\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;

        if (newNode->nextNode == NULL)
            tail = newNode;
    }

    // d) Delete from start
    void pop_front()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->nextNode;

        if (head == NULL)
            tail = NULL;

        delete temp;
    }

    // e) Delete from end
    void pop_back()
    {
        if (head == NULL)
            return;

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->nextNode != tail)
        {
            temp = temp->nextNode;
        }

        delete tail;
        tail = temp;
        tail->nextNode = NULL;
    }

    // f) Delete from nth position
    void deleteAt(int pos)
    {
        if (pos < 0 || head == NULL)
            return;

        if (pos == 0)
        {
            pop_front();
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->nextNode;
        }

        if (temp == NULL || temp->nextNode == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *del = temp->nextNode;
        temp->nextNode = del->nextNode;

        if (del == tail)
            tail = temp;

        delete del;
    }

    // g) Search key
    void search(int val)
    {
        Node *temp = head;
        int index = 0;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                cout << "Value found at index " << index << endl;
                return;
            }

            temp = temp->nextNode;
            index++;
        }

        cout << "Value not found\n";
    }

    // h) Update list
    void update(int pos, int newVal)
    {
        Node *temp = head;
        int index = 0;

        while (temp != NULL)
        {
            if (index == pos)
            {
                temp->data = newVal;
                return;
            }
            temp = temp->nextNode;
            index++;
        }

        cout << "Invalid position\n";
    }

    // i) Empty list
    void clear()
    {
        while (head != NULL)
        {
            pop_front();
        }
    }

    // j) Calculate size
    int size()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->nextNode;
        }

        return count;
    }

    void printListItems()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->nextNode;
        }

        cout << "NULL\n";
    }
};

int main()
{
    List ll;

    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);

    ll.printListItems();

    ll.push_back(5);
    ll.push_back(6);
    ll.printListItems();

    ll.insert(10, 2);
    ll.printListItems();

    ll.deleteAt(2);
    ll.printListItems();

    ll.search(5);

    ll.update(1, 99);
    ll.printListItems();

    cout << "Size = " << ll.size() << endl;

    ll.clear();
    ll.printListItems();

    return 0;
}