#include <iostream>

using namespace std;

class RationalNumber
{
private:
    int numerator = 0, denominator = 0;
public:
    void assign(int p, int q)
    {
        if(q != 0)
        {
            numerator = p, denominator = q;
        }
        else cout << "Error: Can not assign, Unknown values inserted\n";
    }
    double convert()
    {
        if(denominator != 0)
        {
            return double(numerator)/denominator;
        }
        else cout << "Error: Mathematical Undefined, Denominator = 0\n";
    }
    void invert()
    {
        int temp = denominator;

        denominator = numerator;
        numerator = temp;

        //else "Error: Can not be converted, it becomes mathematical undefined\n";
    }
    void print()
    {
        cout << "The Rational Number is " << numerator << "/" << denominator << "\n";
    }
} ;


int main()
{
    int c = 0;

    RationalNumber rn;

    int num1, num2;
    cout << "Enter numerator & denominator respectively: ";
    cin >> num1 >> num2;

    rn.assign(num1, num2);

    rn.print();

    cout << "Result = " << rn.convert() << "\n" << "Inverted >> ";

    rn.invert();

    rn.print();

    cout << "\n\n";


    return 0;
}
