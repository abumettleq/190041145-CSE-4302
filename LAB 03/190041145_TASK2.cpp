#include <iostream>

using namespace std;

class FLOAT
{
private:
    float number;
public:
    FLOAT() : number(0)
    { }
    ~FLOAT()
    { }

    Float(float f1)
    {
        number = (int) f1;
    }

    void number_setter(float val)
    {
        number = val;
    }

    FLOAT operator + (FLOAT f)
    {
        FLOAT returned_float;

        returned_float.number = number + f.number;

        return returned_float;
    }
    FLOAT operator - (FLOAT f)
    {
        FLOAT returned_float;

        returned_float.number = number - f.number;

        return returned_float;
    }
    FLOAT operator / (FLOAT f)
    {
        FLOAT returned_float;

        returned_float.number = number / f.number;

        return returned_float;
    }
    FLOAT operator * (FLOAT f)
    {
        FLOAT returned_float;

        returned_float.number = number * f.number;

        return returned_float;
    }

    void display()
    {
        cout << number << endl;
    }
};

int main()
{
    FLOAT f1, f2,f3,f4;

    f1.number_setter(1.1);
    f2.number_setter(1.4);
    f3.number_setter(1.7);

    f4 = f2 + f3;
    f4.display();

    f4 = f4 - f1;
    f4.display();

    f4 = f2 * f3;
    f4.display();

    f4 = f4 / f1;
    f4.display();

    f1.display();

    return 0;
}
