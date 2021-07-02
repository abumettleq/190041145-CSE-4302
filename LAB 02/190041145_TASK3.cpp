#include <iostream>

using namespace std;

class ZooAnimal
{
private:

    string nameofAnimal;
    int birthYear;
    int cageNumber;
    float weight;
    int height;

public:

    ZooAnimal()
    {
        nameofAnimal = "";
        birthYear = 2021;
        cageNumber = 0;
        weight = 0;
        height = 0;
    }

    void name_setter(string name)
    {
        nameofAnimal = name;
    }
    string name_getter()
    {
        return nameofAnimal;
    }

    void birthYear_setter(int year)
    {
        if(year < 2021)
        {
            birthYear = year;
        }
        else cout << "BirthYear can not be set to higher than 2021!\n";
    }
    int birthYear_getter()
    {
        return birthYear;
    }

    void cageNumber_setter(int cage)
    {
        cageNumber = cage;
    }
    int cageNumber_getter()
    {
        return cageNumber;
    }

    void weight_setter(float wt)
    {
        weight = wt;
    }
    float weight_getter()
    {
        return float(weight);
    }

    void height_setter(int ht)
    {
        height = ht;
    }
    int height_getter()
    {
        return height;
    }

    void getAge()
    {
        cout << "Age of " << nameofAnimal << " is " << 2021 - birthYear << " year\n";
    }

    void getInformation()
    {
        cout << "Animal name: " << nameofAnimal << "\nBirth Year: " << birthYear << "\nCage No.: " << cageNumber << "\nWeight: " << weight << "\nHeight: " << height << endl;
    }

};

int main()
{
    ZooAnimal zoo1;

    zoo1.name_setter("Horse");
    cout << zoo1.name_getter() << endl;

    zoo1.birthYear_setter(2020);
    cout << zoo1.birthYear_getter()<< endl;

    zoo1.cageNumber_setter(87);
    cout << zoo1.cageNumber_getter()<< endl;

    zoo1.weight_setter(4.7);
    cout << zoo1.weight_getter()<< endl;

    zoo1.height_setter(2);
    cout << zoo1.height_getter()<< endl;

    zoo1.getInformation();
    zoo1.getAge();

    return 1;
}
