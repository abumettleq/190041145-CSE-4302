#include <iostream>

using namespace std;

class Calculator
{
private:

    int val;

public:

    Calculator()
    {

    }
    ~Calculator()
    {
        cout << "Calculator object is destroyed\n";
    }

    Calculator(int val)
    {
        val = val;
    }

    void add(int value)
    {
        val = val + value;
    }
    void subtract(int value)
    {
        val = val - value;
    }
    void multiply(int value)
    {
        val = val * value;
    }
    void divideby(int value)
    {
        val = val / value;
    }

    int getvalue()
    {
        return val;
    }

    void setvalue()
    {
        val = 0;
    }

    void display()
    {
        cout << "Answer: " << getvalue() << "\n";
    }

    void clear_()
    {
        setvalue(); // reset to 0
        display();

        Calculator c2;
        c2.~Calculator();
    }
};

int main()
{
    int o;
    Calculator calc;
    int choice = 0;

    Calculator(0);

    while(choice != -1)
    {
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Display\n6. Clear\n-1. Exit\nchoice> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter operand: ";
            cin >> o;
            calc.add(o);
            calc.display();
            break;
        case 2:
            cout << "Enter operand: ";
            cin >> o;
            calc.subtract(o);
            calc.display();
            break;
        case 3:
            cout << "Enter operand: ";
            cin >> o;
            calc.multiply(o);
            calc.display();
            break;
        case 4:
            cout << "Enter operand: ";
            cin >> o;
            if(o == 0)
            {
                cout << "Error: Can not divide by 0!\n";
                break;
            }
            calc.divideby(o);
            calc.display();
            break;
        case 5:
            calc.display();
            break;
        case 6:
            calc.clear_();
            break;
        }
    }

    return 0;
}
