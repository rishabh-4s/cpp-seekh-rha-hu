#include <iostream>
using namespace std;

void inplaceHeapSort(int input[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (input[childIndex] < input[parentIndex])
            {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    // remove elements

    int size = n;
    while (size > 1)
    {
        int temp = input[0];
        input[0] = input[size - 1];

        input[size - 1] = temp;

        size--;

        int parentIndex = 0;
        int lci = 2 * parentIndex + 1;
        int rci = 2 * parentIndex + 2;

        while (lci < size)
        {
            int minIndex = parentIndex;
            if (input[minIndex] > input[lci])
                minIndex = lci;

            if (rci < size && input[rci] < input[minIndex])
                minIndex = rci;

            if (minIndex == parentIndex)
                break;

            int temp = input[minIndex];
            input[minIndex] = input[parentIndex];
            input[parentIndex] = temp;

            parentIndex = minIndex;
            lci = 2 * parentIndex + 1;
            rci = 2 * parentIndex + 2;
        }
    }
}

int main()
{
    int input[] = { 5, 1, 2, 0, 8};
    inplaceHeapSort(input, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    
}