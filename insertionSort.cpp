#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    clock_t st, en;
    st = clock();
    for (int k = 0; k < 4; k++)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            int a = (rand() % (2 * n));
            arr[i] = a;
        }

        insertionSort(arr, n);
        en = clock();
        double tt = double(en - st) / double(CLOCKS_PER_SEC);
        cout << "\ntime taken: " << fixed
             << tt << setprecision(1);
        cout << "secs" << endl;
    }
    return 0;
}
