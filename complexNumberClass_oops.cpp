#include <iostream>
using namespace std;
class complexNumbers
{
private:
    int real;
    int imaginary;

public:
    complexNumbers(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void print()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    void plus(complexNumbers const &c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }

    void multiply(complexNumbers const &c2)
    {
        int temp_real = real;
        real = (real * c2.real) - (imaginary * c2.imaginary);
        imaginary = (temp_real * c2.imaginary) + (c2.real * imaginary);
    }
};

int main()
{
    int real1, imgaginary1, real2, imgaginary2;
    cin >> real1 >> imgaginary1;
    cin >> real2 >> imgaginary2;

    complexNumbers c1(real1, imgaginary1);
    complexNumbers c2(real2, imgaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
}