#include <iostream>

using namespace std;

class Counter
{
private:

    int count = 0, increase = 0;


public:

    void setIncrementStep(int step_val)
    {
        increase = step_val;
    }
    void increment()
    {
        count = count + increase;
    }

    int getCount()
    {
        return count;
    }

    void resetCount()
    {
        count = 0;
    }
};




int main()
{
    Counter c1;
    int num = 0;

    int c = 0;
    while(c++ != -1)
    {
        cout << "Enter a number: ";
        cin >> num;

        if(num == -1)
        {
            c1.resetCount();
            cout << "Count reseted to " << c1.getCount() << "\n\n";
            continue;
        }


        c1.setIncrementStep(num);

        c1.increment();
        cout << "Count: " << c1.getCount() << "\n\n";
    }
    return 0;
}
