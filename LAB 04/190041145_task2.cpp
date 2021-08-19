#include <iostream>

using namespace std;

class Building
{
private:
    string buidling_name;

public:
    Building(){}
    Building(string name)
    {
        buidling_name = name;
    }

    void showAllLabs()
    {
        cout << "Welcome to "<< buidling_name <<" Building\n";
        cout << "Show all Labs:\n";
    }

    void showAllLecturerRoom()
    {
        cout << "Show all Rooms:\n";
    }
};

class Lab : public Building
{
private:
    string labName[50];
    int capacity[50];

public:
    Lab(){}
    ~Lab(){}

    int count = 0;

    string getLabName(int pos)
    {
        return labName[pos];
    }
    int getCapacity(int pos)
    {
        return capacity[pos];
    }

    void setLabName(int pos, string name)
    {
        labName[pos] = name;
        count++;
    }
    void setCapacity(int pos, int cap)
    {
        capacity[pos] = cap;
    }
};

class Room : public Building
{
private:
    string roomName[50];
    int roomNo[50];
    int capacity[50];

public:
    Room(){}
    ~Room(){}

    int count = 0;

    string getRoomName(int pos)
    {
        return roomName[pos];
    }
    int getRoomNo(int pos)
    {
        return roomNo[pos];
    }
    int getCapacity(int pos)
    {
        return capacity[pos];
    }

    void setRoomName(int pos, string name)
    {
        roomName[pos] = name;
        count++;
    }
    void setRoomNo(int pos, int no)
    {
        roomNo[pos] = no;
    }
    void setCapacity(int pos, int cap)
    {
        capacity[pos] = cap;
    }
};

int main()
{
    Building bld("N28");

    Lab lb;

    lb.setLabName(0, "MPK1"); lb.setCapacity(0, 60);
    lb.setLabName(1, "MPK2"); lb.setCapacity(1, 60);
    lb.setLabName(2, "MPK3"); lb.setCapacity(2, 50);
    lb.setLabName(3, "MPK4"); lb.setCapacity(3, 50);

    Room rm;
    rm.setRoomName(0, "Hafiz"); rm.setRoomNo(0, 102); rm.setCapacity(0, 3);
    rm.setRoomName(1, "Shafie"); rm.setRoomNo(1, 105); rm.setCapacity(1, 3);
    rm.setRoomName(2, "Aisyah"); rm.setRoomNo(2, 202); rm.setCapacity(2, 3);
    rm.setRoomName(3, "Rahim"); rm.setRoomNo(3, 208); rm.setCapacity(3, 3);


    bld.showAllLabs();
    for(int i = 0; i < lb.count; i++)
    {
        cout << "Lab " << lb.getLabName(i) << " " << lb.getCapacity(i) << " Capacity" << endl;
    }

    bld.showAllLecturerRoom();
    for(int i = 0; i < rm.count; i++)
    {
        cout << rm.getRoomName(i) << " " << rm.getRoomNo(i) << " " << rm.getCapacity(i) << " Capacity" << endl;
    }

    return 0;
}
