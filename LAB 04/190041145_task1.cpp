#include <iostream>
#include <string>

using namespace std;

class Account
{
private:
    string accountNo;
    string accountName;
    float balance;
    string accountType;

public:
    Account()
    {
        accountName = '\0';
        accountNo = '\0';
        accountType = '\0';
    }
    Account(string acc_no, string type)
    {
        accountNo = acc_no;
        accountType = type;
    }
    ~Account(){}
    void description()
    {
        cout << "\nAccount Name: " << accountName << "\nAccount Number: " << accountNo << "\nBalance: " << balance << "\nType: " << accountType << endl;
    }

    void accountName_setter()
    {
        cout << "\nEnter Account Name: ";
        fflush(stdin);
        getline(cin, accountName);
    }

    void balance_setter()
    {
        cout << "Enter Balance: ";
        cin >> balance;
        balance = balance;
    }
    void balance_setter(float serviceCharge)
    {
        cout << "Enter Balance: ";
        cin >> balance;
        balance = balance - serviceCharge;
    }


};

class CurrentAccount : public Account
{
private:
    inline static const string serviceCharge = "100";
    inline static const string accountPrefix = "100";
    string nextAccount;

    void nextAccountNo()
    {
        int randomNo = 10000000 + (rand() % 99999999); //generates 8-digit random number
        nextAccount = to_string(randomNo);
    }

public:
    CurrentAccount()
    {
        //string CurrentAccount::nextAccount = accountPrefix + "-" + to_string(randomNo);
        nextAccountNo();

        Account new_acc(accountPrefix + nextAccount, "Current Account");
        new_acc.accountName_setter();
        new_acc.balance_setter(stoi(serviceCharge));

        new_acc.description();
    }
    ~CurrentAccount(){}
};

class SavingsAccount : public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    inline static const string accountPrefix = "200";
    string nextAccount;

    void nextAccountNo()
    {
        int randomNo = 10000000 + (rand() % 99999999); //generates 8-digit random number
        nextAccount = to_string(randomNo);
    }

public:
    SavingsAccount()
    {
        nextAccountNo();

        Account new_acc(accountPrefix + nextAccount, "Savings Account");
        new_acc.accountName_setter();
        new_acc.balance_setter();

        new_acc.description();
    }
    ~SavingsAccount(){}

    void monthlyDepositAmount_setter(float Amount)
    {
        monthlyDepositAmount = Amount;
    }
    float monthlyDepositAmount_getter()
    {
        return float(monthlyDepositAmount);
    }

    void interestRate_setter(float interest)
    {
        interestRate = interest;
    }
    float interestRate_getter()
    {
        return float(interestRate);
    }
};

class MonthlyDepositScheme : public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    inline static const string accountPrefix = "300";
    string nextAccount;

    void nextAccountNo()
    {
        int randomNo = 10000000 + (rand() % 99999999); //generates 8-digit random number
        nextAccount = to_string(randomNo);
    }

public:
    MonthlyDepositScheme()
    {
        nextAccountNo();

        Account new_acc(accountPrefix + nextAccount, "Monthly Deposit Scheme");
        new_acc.accountName_setter();
        new_acc.balance_setter();

        new_acc.description();
    }
    ~MonthlyDepositScheme(){}

    void monthlyDepositAmount_setter(float Amount)
    {
        monthlyDepositAmount = Amount;
    }
    float monthlyDepositAmount_getter()
    {
        return float(monthlyDepositAmount);
    }

    void interestRate_setter(float interest)
    {
        interestRate = interest;
    }
    float interestRate_getter()
    {
        return float(interestRate);
    }
};

class InitialDepositMDS : public MonthlyDepositScheme
{
private:
    float maximuminterest;
    float initialDepositAmount;

public:
    InitialDepositMDS(){}
    ~InitialDepositMDS(){}

    void maximuminterest_setter(float interest)
    {
        maximuminterest = interest;
    }
    float maximuminterest_getter()
    {
        return float(maximuminterest);
    }

    void initialDepositAmount_setter(float Amount)
    {
        initialDepositAmount = Amount;
    }
    float initialDepositAmount_getter()
    {
        return initialDepositAmount;
    }
};

class TwoYearMDS : public MonthlyDepositScheme
{
private:
    float maximuminterest;

public:
    TwoYearMDS(){}
    ~TwoYearMDS(){}

    void maximuminterest_setter(float interest)
    {
        maximuminterest = interest;
    }
    float maximuminterest_getter()
    {
        return float(maximuminterest);
    }
};

class FiveYearMDS : public MonthlyDepositScheme
{
private:
    float maximuminterest;

public:
    FiveYearMDS(){}
    ~FiveYearMDS(){}

    void maximuminterest_setter(float interest)
    {
        maximuminterest = interest;
    }
    float maximuminterest_getter()
    {
        return float(maximuminterest);
    }
};

class LoanAccount : public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    inline static const string accountPrefix = "900";
    string nextAccount;

    void nextAccountNo()
    {
        int randomNo = 10000000 + (rand() % 99999999); //generates 8-digit random number
        nextAccount = to_string(randomNo);
    }

public:
    LoanAccount()
    {
        nextAccountNo();

        Account new_acc(accountPrefix + nextAccount, "Loan Account");
        new_acc.accountName_setter();
        new_acc.balance_setter();

        new_acc.description();
    }
    ~LoanAccount(){}

    void monthlyDepositAmount_setter(float Amount)
    {
        monthlyDepositAmount = Amount;
    }
    float monthlyDepositAmount_getter()
    {
        return float(monthlyDepositAmount);
    }

    void interestRate_setter(float interest)
    {
        interestRate = interest;
    }
    float interestRate_getter()
    {
        return float(interestRate);
    }

};

int main()
{
    CurrentAccount acc;

    SavingsAccount acc2;

    MonthlyDepositScheme acc3;

    LoanAccount acc4;

    return 0;
}
