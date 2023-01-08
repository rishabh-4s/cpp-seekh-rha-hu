#include <bits/stdc++.h>
using namespace std;

vector<int> foo(vector<int> arr)
{
    vector<int> product(arr.size());
    int i = 0;
    int j = arr.size()-1;
    int left = 1;
    int right = 1;
    for (int k = 0; k < arr.size(); k++)
    {
        product[k] = 1;
        //cout << product[k] << " ";
    }
    //cout << endl;
    
    while (i < arr.size()- 1 && j > 0)
    {
        
        left *= arr[i];
        right *= arr[j];
        i++;
        j--;
        product[i] *= left;
        product[j] *= right;

    }
    return product;
    

}

int main()
{
    vector<int> arr = {-1,1,0,-3,3};
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    vector<int> hell = foo(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << hell[i] << " ";
    }
    
    return 0;
}