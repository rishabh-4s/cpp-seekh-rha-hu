#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return 1;
    return 0;
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

        search(arr, n, n * 1.5);
        
        en = clock();
        double tt = double(en - st) / double(CLOCKS_PER_SEC);
        cout << "\ntime taken: " << fixed
             << tt << setprecision(1);
        cout << "secs" << endl;
        
    }

    return 0;
}