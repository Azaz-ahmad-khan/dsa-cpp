#include <iostream>
// #include <algorithm>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[iMin])
            {
                iMin = j;
                if (iMin != j)
                {

                    swap(arr[iMin], arr[j]);
                }
            }
        }
    }
}

int main()
{
}