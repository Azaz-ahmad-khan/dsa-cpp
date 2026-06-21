#include <iostream>
using namespace std;

int *mergArray(int arrA[], int sizeA, int arrB[], int sizeB)
{
    int *mergedArray = new int[sizeA + sizeB];
    for (int i = 0; i < sizeA + sizeB; i++)
    {
        *(mergedArray + i) = -1;
    }
    for (int i = 0; i < sizeA; i++)
    {
        *(mergedArray + i) = arrA[i];
    }
    int firstIndex = 0;
    for (int i = sizeA; i < sizeA + sizeB; i++)
    {

        *(mergedArray + i) = arrB[firstIndex];
        firstIndex += 1;
    }

    return mergedArray;
}
int main()
{
    int arrA[] = {1, 2, 3, 4, 5};
    int sizeA = 5;
    int arrB[] = {6, 7, 8, 9, 10, 11};
    int sizeB = 6;
    int *mergedArray = mergArray(arrA, sizeA, arrB, sizeB);
    for (int i = 0; i < sizeA + sizeB; i++)
    {
        cout << *(mergedArray + i) << ",";
    }
    delete[] mergedArray;
}
