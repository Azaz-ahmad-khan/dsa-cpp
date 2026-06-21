#include <iostream>
using namespace std;
bool linSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int arr[5] = {3, 4, 5, 6, 7};
    bool isPresent = linSearch(arr, 5, 5);
    isPresent ? cout << "the item is present" : cout << "item not found" << endl;
}