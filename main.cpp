#include <iostream>
#include "OOPS_2.cpp"


using namespace std;

int main(){
    char name[] = "abcd";
    Student s1(10, name);
    s1.display();

    Student s2(s1);
    s2.name[0] = 'x';
    s1.display();
    s2.display();
    return 0;
}

                                                    