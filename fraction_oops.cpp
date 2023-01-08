#include <iostream>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print()
    {
        cout << numerator << " / " << this->denominator << endl;
    }

    fraction add(fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = x * numerator + (y * f2.numerator);

        //numerator = num;
        //denominator = lcm;
        fraction ans(num, lcm);
        return ans;

        //simplify();
    }
    void simplify()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
                gcd = i;
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
};

int main()
{
    fraction f1(15, 4);
    fraction f2(1, 2);
    fraction ans = f1.add(f2);
    ans.print();
    //f1.add(f2);
    //f1.print();
    //f1.simplify();
    //f1.print();
}