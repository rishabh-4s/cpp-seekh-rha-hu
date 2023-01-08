#include <bits/stdc++.h>
using namespace std;

class hello
{   protected:
    virtual void hi(); 
};
class me : public hello
{
    public:
    void hi()
    {
        cout << 1;
    }
};

int main()
{
    me m;
    m.hi();
    return 0;
}