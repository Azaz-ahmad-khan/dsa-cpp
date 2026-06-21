#include <iostream>
#include <stdexcept>
using namespace std;

class List
{
private:
    int *data;
    int size;
    int capacity;

    void resize()
    {
        capacity *= 2;
        int *newdata = new int[capacity];
        for (int i = 0; i < size; i++)
            newdata[i] = data[i];
        delete[] data;
        data = newdata;
    }

public:
    List() : size(0), capacity(4)
    {
        data = new int[capacity];
    }

    ~List()
    {
        delete[] data;
    }

    void push_back(int val)
    {
        if (size == capacity)
            resize();
        data[size++] = val;
    }

    void pop_back()
    {
        if (size == 0)
            throw underflow_error("list is empty"); // ✅ fixed
        size--;
    }

    int get(int index)
    {
        if (index < 0 || index >= size) // ✅ fixed: was index==0
            throw out_of_range("index does not exist");
        return data[index];
    }

    void insert(int index, int val)
    {                                  // ✅ fixed: swapped param order
        if (index < 0 || index > size) // ✅ fixed: was index==0
            throw out_of_range("index does not exist");
        if (size == capacity)
            resize(); // ✅ fixed: no longer in if/else
        for (int i = size; i > index; i--)
            data[i] = data[i - 1];
        data[index] = val; // ✅ fixed: outside the loop
        size++;            // ✅ fixed: outside the loop
    }

    void remove(int index)
    {
        if (index < 0 || index >= size)
            throw out_of_range("index out of bounds");
        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
    }

    int getSize() const { return size; }

    void print() const
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << "]\n";
    }
};

int main()
{
    List lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.print(); // [ 10 20 30 ]

    lst.insert(1, 15);
    lst.print(); // [ 10 15 20 30 ]

    lst.remove(2);
    lst.print(); // [ 10 15 30 ]

    lst.pop_back();
    lst.print(); // [ 10 15 ]

    cout << "Element at index 0: " << lst.get(0) << "\n"; // 10

    return 0;
}