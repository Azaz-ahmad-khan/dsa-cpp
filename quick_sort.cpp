#include <iostream>
#include <vector>
using namespace std;

// Partition function (Lomuto partition scheme)
int partition(vector<int> &array, int start, int end)
{
    int pivot = array[end]; // Last element as pivot
    int index = start - 1;  // Smaller element boundary

    for (int current = start; current < end; current++)
    {
        if (array[current] <= pivot)
        {
            index++;
            swap(array[current], array[index]);
        }
    }

    // Place pivot in correct position
    index++;
    swap(array[end], array[index]);

    return index; // Pivot index
}

// Quick Sort function
void quickSort(vector<int> &array, int start, int end)
{
    if (start < end)
    {
        int pivotIndex = partition(array, start, end);

        // Left subarray
        quickSort(array, start, pivotIndex - 1);

        // Right subarray
        quickSort(array, pivotIndex + 1, end);
    }
}

// Print function
void printArray(const vector<int> &array)
{
    for (int value : array)
    {
        cout << value << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    vector<int> array = {12, 31, 35, 8, 32, 17};

    cout << "Original array: ";
    printArray(array);

    quickSort(array, 0, array.size() - 1);

    cout << "Sorted array: ";
    printArray(array);

    return 0;
}
