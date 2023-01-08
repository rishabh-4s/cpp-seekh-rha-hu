#include <iostream>
#include "string.h"
using namespace std;

class student
{

    int age;
    char *name;

    student(int age, char *name)
    {

        this->age = age;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {

        cout << age << " " << name << endl;
    }
};
int main()
{
    return 0;
}