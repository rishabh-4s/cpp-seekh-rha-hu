#include <iostream>
#include <string>
using namespace std;

void match(string pat, string txt)
{
    int n = pat.length();
    int m = txt.length();
    //cout << n << endl;

    for (int i = 0; i < m; i++)
    {
        if (txt[i] = pat[0])
        {
            
            
            int j;
            for (j = 0; j < n; j++)
            {
                
                if (pat[j] != txt[i + j])
                    break;
                //cout << pat[j] << " "<< txt[i + j] << endl;
                
            }
            if (j == n)
                cout << i << " ";
        }
    }
}
int main()
{
    string txt = "AKDJHFAJABABKDFABAHA";
    string pat = "ABA";
    match(pat, txt);
}


