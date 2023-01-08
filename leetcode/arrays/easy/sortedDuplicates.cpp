#include <iostream>
using namespace std;

int *delSortDup(int *arr, int n)
{
    int k = 0;
    int curr = arr[0];
    int uni = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == curr)
        {
            continue;

            
        }
        else
        {
            curr = arr[i];
            arr[uni] = arr[i];
            k++;
            uni++;
        }

    }
    return arr;
    
}
int main()
{
    int *arr = new int[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    arr = delSortDup(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    
}