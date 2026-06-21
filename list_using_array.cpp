// this is the practice which was done in the lab

#include <iostream>
#define MAX 100
#include <string>
using namespace std;

struct ELEMENT
{
    int numb;
    string data;
};
struct LIST
{
    ELEMENT a[MAX];
    int size;
    void creatList(LIST *list)
    {
        list->size = 0;
    }
    void add(LIST *list, int index, ELEMENT item)
    {

        if (list->size == MAX)
        {
            cout << "List is full!";
            return;
        }
        // lis->size is always =index-1
        if (index < 0 || index > list->size)
        {
            cout << "out of bound";
            return;
        }
        for (int i = list->size; i > index; i--)
        {
            list->a[i] = list->a[i - 1];
        }
        list->a[index] = item;
        list->size++;
        cout << "Added " << endl;
    }
    void delet(LIST *list, int index, ELEMENT element)
    {

        if (index > MAX || index < 0 || index >= list->size)
        {
            cout << "out of bound index" << endl;
            return;
        }
        for (int i = index; i < list->size; i++)
        {
            list->a[i] = list->a[i + 1];
        }
        list->size--;
        cout << "deleted" << endl;
    }
    ELEMENT getF(LIST *list, int index)
    {
        ELEMENT temp = {0, "N/A"};
        if (index < 0 || index >= list->size)
        {
            cout << "out of bound" << endl;
            return temp;
        }
        return list->a[index];
    }
    int size(LIST *list)
    {
        return list->size;
    }
    int start(LIST *list)
    {

        return 0;
    }
    int end(LIST *list)
    {
        return list->size - 1;
    }
    bool isEmpty(LIST *list)
    {
        if (list->size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    LIST list;
    ELEMENT item;
    list.creatList(&list);
    item.numb = 1;
    item.data = "one";
    list.add(&list, 0, item);
}