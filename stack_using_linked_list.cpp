#include<iostream>
using namespace std;
class Node{
 public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=nullptr;
    }

};
class Stack{
    Node *topNode;
    int count;

public:
    Stack(){
        topNode=nullptr;
        count=0;
    }
    ~Stack(){
        while (!isEmpty())
        {
            pop();
        }
    }
    void push(int value){
        Node *newNode=new Node(value);
        newNode->next=topNode;
        topNode=newNode;
        count++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"The stack is empty no item to be popped"<<endl;
            return -1;
        }
        Node *temp=topNode;
        int value=temp->data;
        topNode=temp->next;
        count--;
        delete temp;
        return value;
    }
    bool isEmpty(){
        return topNode==nullptr;
    }
    int top(){
        if (isEmpty())
        {
            cout<<"the stack is empty"<<endl;
            return -1;
        }
        return topNode->data;
    }
    int size(){
        return count;
    }
};
int main(){
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Top element: "<<s.top()<<endl;
    cout<<"Size: "<<s.size()<<endl;

    int popped=s.pop();
    cout<<"Popped element: "<<popped<<endl;

    cout<<"Top element after pop: "<<s.top()<<endl;
    cout<<"Size after pop: "<<s.size()<<endl;
    cout<<"Is empty: "<<(s.isEmpty()?"true":"false")<<endl;

    return 0;
}