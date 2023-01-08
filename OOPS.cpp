#include <iostream>
using namespace std;
class student
{
private:
    int age;

public:
    int rollNumber;

    student()
    {
        cout << "haan vai kiski" << endl;
    }

    student(int r)
    {
        rollNumber = r;
        cout << "badia sab" << endl;
    }
    void display()
    {
        cout << rollNumber << endl;
    }
};
