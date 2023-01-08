#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        
    }
    cout << endl;
    
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, mini;
    for (i = 0; i < n - 1; i++)
    {
        mini = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
            
        }
        swap(&arr[mini], &arr[i]);
        // printing array after every pass
        display(arr, n);
    }
}

int main()
{
    int arr[] = {63, 87, 18, 13, 10, 93, 11, 15};
    selectionSort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}