#include <iostream>
using namespace std;

int b_Search(int arr[], int size, int key)
{
    int s = 0;
    int end = size;
    while (s <= end)
    {
        int mid = (s + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int main()
{

    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "please enter the " << i + 1 << " value of array :";
        cin >> arr[i];
        cout << endl;
    }

    cout << b_Search(arr, 5, 3)+1;
}