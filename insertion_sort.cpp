#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 2, 1, 7, 4, 5, 6};
    int count = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < count; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}