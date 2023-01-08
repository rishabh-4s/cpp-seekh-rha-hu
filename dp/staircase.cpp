#include <iostream>
using namespace std;

// total ways to climb a staircase
// can jump 1/ 2/ 3 stairs at a time

int stairu(int n){
    if (n == 0) return 0;
    int stair[n+1];
    stair[0] = 1;
    stair[1] = 1;
    stair[2] = 2;
    
    for (int i = 3; i < n + 1; i++)
    {
        stair[i] = stair[i - 1] + stair[i - 2] + stair[i - 3];
    }
    return stair[n];
    
    

}

int main()
{
    int res = stairu(10);
    cout << res;
}