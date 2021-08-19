#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string productName;

public:
    double discounted_price;

    Furniture(string pn,double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setProductName(pn);
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setDiscountedPrice();
    }
    void setProductName(string str)
    {
        productName = str;
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setDiscountPercentage(double val)
    {
        val = val/100;
        discounted_price = price * val;
    }
    void setDiscountedPrice()
    {
        discounted_price = price - discount;
    }
    void updateDiscountedPrice(int val)
    {
        discounted_price = discounted_price - val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails() = 0;

};



enum class BedSize {Single,SemiDouble,Double};

class Bed: public Furniture
{
private:
    BedSize bed_size;
public:
    Bed(string pName,double prc, double discnt, Material mtrl, BedSize size) : Furniture(pName, prc, discnt, mtrl), bed_size(size)
    {}

    void productDetails()
    {
        cout << "---------------------------" << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << discounted_price << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Bed Size: ";
        switch (bed_size)
        {
        case BedSize::Double:
            cout << "Double\n";
            break;
        case BedSize::SemiDouble:
            cout << "SemiDouble\n";
            break;
        case BedSize::Single:
            cout << "Single\n";
            break;
        }
    }

};

enum class SeatNumber {One, Two, Three, Four, Five};

class Sofa:public Furniture
{
private:
    SeatNumber seat_number;
public:
    Sofa(string sName,double prc, double discnt, Material mtrl, SeatNumber seat) : Furniture(sName, prc, discnt, mtrl), seat_number(seat)
    {}


    void productDetails()
    {
        cout << "---------------------------" << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << discounted_price << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Seat Number: ";
        switch (seat_number)
        {
        case SeatNumber::One:
            cout << "One\n";
            break;
        case SeatNumber::Two:
            cout << "Two\n";
            break;
        case SeatNumber::Three:
            cout << "Single\n";
            break;
        case SeatNumber::Four:
            cout << "Four\n";
            break;
        case SeatNumber::Five:
            cout << "Six\n";
            break;
        }
    }
};

enum class AlmirahSize {Single, Double};

class Almirah:public Furniture
{
private:
    AlmirahSize door_num;

public:
    Almirah(string aName, double prc, double discnt, Material mtrl, AlmirahSize door) : Furniture(aName, prc, discnt, mtrl), door_num(door)
    {}

    void productDetails()
    {
        cout << "---------------------------" << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << discounted_price << endl;
        cout << "Material: " << getMadeof() << endl;
        cout << "Seat Number: ";
        switch (door_num)
        {
        case AlmirahSize::Single:
            cout << "One\n";
            break;
        case AlmirahSize::Double:
            cout << "Two\n";
            break;
        }
    }

};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures)
{
    Furniture *t;

    for (int i = 0 ; i < ( no_of_furnitures - 1 ); i++)
    {
        for (int j = 0 ; j < no_of_furnitures - i - 1; j++)
        {
            if (furnitures[j]->discounted_price < furnitures[j+1]->discounted_price)
            {
                /* Swapping */
                t = furnitures[j];
                (furnitures[j]) = (furnitures[j+1]);
                (furnitures[j+1]) = (t);
            }
        }
    }
}


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed("OnePerson Bed",10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa("FivePeople Sofa",11000,234,Material::Steel,SeatNumber::Five);
    f_list[2] = new Almirah("DoubleDoor Almirah",13000,0,Material::Wood,AlmirahSize::Double);
    f_list[3] = new Bed("OnePerson Bed",10090,123,Material::Wood,BedSize::SemiDouble);
    f_list[4] = new Bed("TwoPeople Bed",14500,300,Material::Wood,BedSize::Double);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscountPercentage(30);
    for(int i=0; i<5; i++)
    {
        f_list[i]->productDetails();
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list,5);

    cout << "\n>>> Price Descending Order <<<" << endl;

    for(int i=0; i<5; i++)
    {
        f_list[i]->productDetails();
    }

    cout << "\nAfter 15tk discount \n";

    f_list[0]->updateDiscountedPrice(15);
    f_list[1]->updateDiscountedPrice(15);

    for(int i=0; i<2; i++)
    {
        f_list[i]->productDetails();
    }

    /**task 4 ends here*/


    cout << "---------------------------" << endl;
    return 0;

}
