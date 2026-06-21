#include <iostream>
#define MAX 100
#include <string>
using namespace std;

struct item
{
    int numb;
};
struct LIST
{
    int size;
    item list[MAX];
    void createList(LIST *list)
    {
        list->size = 0;
    }
    void addToList(LIST *list, int index, item data)
    {
        if (list->size == MAX)
        {
            cout << "List is full";
            return;
        }
        if (index < 0 || index > size)
        {
            cout << "out of bound";
            return;
        }

        for (int i = list->size; i > index; i--)
        {
            list->list[i] = list->list[i - 1];
        }
        list->list[index] = data;
        size++;
        cout << "Added \n";
    }

    void deleteItem(LIST *list, int index)
    {
        if (index < 0 || index > list->size)
        {
            cout << "out of bound";
            return;
        }
        for (int i = index; i < list->size; i++)
        {
            list->list[index] = list->list[index + 1];
        }
        list->size--;
        cout << "deleted";
    }
};

int main()
{
    LIST list;
    item i;
    i.numb = 100;
    item i2;
    i2.numb = 2;
    item i3;
    i3.numb = 300;
    list.createList(&list);
    list.addToList(&list, 0, i);
    list.addToList(&list, 1, i2);
    list.addToList(&list, 2, i2);
    cout << endl;
    list.deleteItem(&list, 2);
}