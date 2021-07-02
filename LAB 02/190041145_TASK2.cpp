#include <iostream>

using namespace std;

class BankAccount
{
private:

    int acc_num;
    string acc_hold;
    string acc_type;
    double curr_balance;
    double mini_balance;

public:

    BankAccount()
    {

    }
    ~BankAccount()
    {
        cout << "Account of Mr. " << acc_hold << " with account no. " << acc_num << " with a balance of value: " << curr_balance << "BDT is destroyed!\n";
    }

    void create_acc(int num, string holder, string type, double current, double minimum)
    {
        acc_num = num;
        acc_type = type;
        acc_hold = holder;
        curr_balance = current;
        mini_balance = minimum;
    }

    void ShowAll()
    {
        cout << "Name: " << acc_hold << "\nAccount No.: " << acc_num << "\nCurrent Balance: " << curr_balance << "\nAccount Type: " << acc_type << "\n";
    }

    void deposit(int balance)
    {
        curr_balance = curr_balance + balance;
    }

    void withdrawal(int balance)
    {
        if( (curr_balance - balance) > mini_balance )
        {
            curr_balance = curr_balance - balance;
        }
        else cout << "Error: can not withdraw under minimum balance!\n";
    }

    void ShowBalance()
    {
        cout << "Current balance: " << curr_balance << endl;
    }

    void giveInterst(double interst)
    {
        curr_balance = curr_balance + (curr_balance * interst);

        /// 102.5 - (0.1 * 2.5)
        curr_balance = curr_balance - (interst * 0.1);
    }

};

int main()
{
    BankAccount acc1;

    acc1.create_acc(190041145, "Alaaeddin M.", "Savings", 25000, 500);
    acc1.ShowBalance();

    acc1.deposit(25000);
    acc1.ShowBalance();

    acc1.withdrawal(10000);
    acc1.ShowBalance();

    acc1.giveInterst(0.25);
    acc1.ShowBalance();

    acc1.ShowAll();

    //acc1.~BankAccount();

    return 1;
}
