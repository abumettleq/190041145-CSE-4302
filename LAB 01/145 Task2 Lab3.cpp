#include <iostream>
#define MAX 30

using namespace std;

class   Product
{
private:
    string name;
    double discountPercent = 0.5, unitPrice = 0;
public:
    void assignName(string ProductName)
    {
        name = ProductName;
    }

    void setPrice(double ProductPrice)
    {
        unitPrice = ProductPrice;
    }

    void setDiscPercent(double Percent)
    {
        if(Percent >= 0 && Percent <= 10)
        {
            discountPercent = Percent;
        }
        else cout << "Discount percentage is invalid, default set to 0.5%\n"; discountPercent = 0.5;
    }

    double getSellingPrice(int nos)
    {
        double price = unitPrice - discountPercent;
        return double(nos * price);
    }

    void display()
    {
        cout << name << " has a unit price BDT " << unitPrice << ". Current discount " << discountPercent<<"%.\n";
    }
};

int main()
{
    Product p1;

    cout << "Enter product name: ";
    string pName;
    getline(cin, pName);
    p1.assignName(pName);


    cout << "Enter product price: ";
    double pPrice;
    cin >> pPrice;
    p1.setPrice(pPrice);


    cout << "Enter product discount percentage: %";
    double pDiscPrice;
    cin >> pDiscPrice;
    p1.setDiscPercent(pDiscPrice);


    p1.display();


    cout << "Enter product no. of units to be sold: ";
    int nos;
    cin >> nos;

    cout <<"Total price after discount: " << p1.getSellingPrice(nos) << endl;

    return 0;
}
