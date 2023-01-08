#include <bits/stdc++.h>
using namespace std;

int maxSumUniqueSubarray(int* arr,int n)
{
      // Create the prefix sum array
    vector<int> preSum(n + 1);
 
    preSum[0] = 0;
 
    for (int i = 1; i <= n; i++)
        preSum[i] = preSum[i - 1] + arr[i - 1];
   
      // Create an hashset containing the index of last occurrence of an element
    vector<int> lastSeen(1e4+1, 0);
   
      // Initialize the resultant global maximum sum with 0.
    int res = 0;
   
      // Initialize two pointers i and j at index 0
      // Traverse the array with the pointer i.
      int j = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
       
          // If the current element has occurred before,
          // reinitialize j with the maximum value between j and
          // the last occurrence of the current element.
        if (lastSeen[num] > 0)
        {
            j = max(j, lastSeen[num]);
        }
       
       
          // Update the resultant global maximum sum
        res = max(res, preSum[i] + num - preSum[j]);
       
          // Update the last occurrence of current element to index i+1.
        lastSeen[num] = i + 1;
    }
 
    return res;
}
int FindMaxSum(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;
  
    for (i = 1; i < n; i++) {
        // Current max excluding i
        excl_new = max(incl, excl);
  
        // Current max including i
        incl = excl + arr[i];
        excl = excl_new;
    }
  
    // Return max of incl and excl
    return max(incl, excl);
}
int main()
{
    vector<int> arr = {1, 2, 7, 7, 4, 3, 6};
    cout << maxSumUniqueSubarray(arr, 7);
    return 0;
}