#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 4, 2, 5, 8, 6, 7};
    int count = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < count - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < count; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }
}