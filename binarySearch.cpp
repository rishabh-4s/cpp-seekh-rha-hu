#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
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

        binarySearch(arr, 0, n, n * 1.5);
        
        en = clock();
        double tt = double(en - st) / double(CLOCKS_PER_SEC);
        cout << "\ntime taken: " << fixed
             << tt << setprecision(1);
        cout << "secs" << endl;
        
    }
    return 0;
}