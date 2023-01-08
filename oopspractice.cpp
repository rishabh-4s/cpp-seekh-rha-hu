#include <bits/stdc++.h>
using namespace std;

class base_class{
    public:
        int name;
        int age;
    
        base_class(int name, int age){
            this->name = name;
            this->age = age;
        }
        
};

class derived_class:base_class{
    public:
        int height;
        derived_class(int height):base_class(name, age)
        {
            this->height = height;
        }

        void print()
        {
            cout << name
        }
};

int main()
{
    
}