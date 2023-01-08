#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    clock_t st, end;
    st = clock();
    for (int k = 0; k < 4; k++)
    {

        int n;
        cin >> n;
        int arr[n];
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            int a = (rand() % (2 * n));
            arr[i] = a;
        }

        mergeSort(arr, 0, n - 1);
        end = clock();
        //cout << "Sorted array: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        double tt = double(end - st) / double(CLOCKS_PER_SEC);
        cout << "\ntime taken: " << fixed
             << tt << setprecision(1);
        cout << "secs" << endl;
    }
    return 0;
}
