#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;
    Node(int val)
    {
        data = val;
        next = previous = NULL;
    }
};

class doubly_List
{
private:
    Node *head;
    Node *tail;

public:
    doubly_List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }
    void print()
    {

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "No Element in the list\n";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        head = temp->next;
        head->previous = NULL;

        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        temp->previous = NULL;
        delete temp;
    }
};

int main()
{
    doubly_List dll;
    dll.push_front(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.print();
    dll.pop_front();
    dll.print();

    dll.pop_back();
    dll.print();
}