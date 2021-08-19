#include <iostream>
#include <math.h>

using namespace std;

class Coordinate
{
private:
    float x, y;
public:
    Coordinate() : x(0), y(0)
    { }
    Coordinate(float init) : x(init), y(init)
    {

    }
    ~Coordinate()
    { }

    float getDistance()
    {
        return sqrt(x*x + y*y);
    }
    float getDistance(Coordinate c)
    {
        return sqrt((x - c.x)*(x - c.x) + (y - c.y)*(y - c.y));
    }

    void move_x(float val)
    {
        x = x + val;
    }
    void move_y(float val)
    {
        y =y + val;
    }
    void move(float val)
    {
        x = x + val;
        y = y + val;
    }

    void display()
    {
        cout << "x = " << x << ", y = " << y << endl;
    }

    Coordinate operator ++ ()
    {
        x+=1;
        y+=1;
    }
    Coordinate operator ++(int)
    {
        Coordinate(x++);
        Coordinate(y++);
    }
    Coordinate operator --()
    {
        x-=1;
        y-=1;
    }
    Coordinate operator --(int)
    {
        Coordinate(x--);
        Coordinate(y--);
    }

    bool operator ==(Coordinate c)
    {
        if(getDistance() == c.getDistance()) return true;
        else return false;
    }
    bool operator !=(Coordinate c)
    {
        if(getDistance() == c.getDistance()) return false;
        else return true;
    }
    bool operator >(Coordinate c)
    {
        if(getDistance() > c.getDistance()) return true;
        else return false;
    }
    bool operator <(Coordinate c)
    {
        if(getDistance() < c.getDistance()) return true;
        else return false;
    }
    bool operator >=(Coordinate c)
    {
        if(getDistance() >= c.getDistance()) return true;
        else return false;
    }
    bool operator <=(Coordinate c)
    {
        if(getDistance() <= c.getDistance()) return true;
        else return false;
    }
};

int main()
{
    Coordinate c1, c2;

    c1.move(1);
    c1.display();
    cout << "Distance from origin: " << c1.getDistance() << endl;

    c2.move_x(2);
    c2.move_y(2);
    c2.display();
    cout << "Distance from origin: " << c2.getDistance() << endl;

    cout << "\nFinding distance between two coordinates:\n";
    cout << c1.getDistance(c2) << endl;


    cout << "c1 after increment: ";
    c1++;
    c1.display();


    cout << "c1 & c2 after decrement:\n";
    c1--;
    c2--;
    c1.display();
    c1.display();


    if(c1 != c2) cout << "c1 == c2\n";
    else cout << "c1 != c2";

    if(c1 >= c2) cout << "c1 == c2\n";
    else cout << "c1 != c2\n";

    if(c1 <= c2) cout << "c1 == c2\n";
    else cout << "c1 != c2\n";

    if(c1 > c2) cout << "c1 != c2\n";
    else cout << "c1 == c2\n";

    if(c1 < c2) cout << "c1 != c2\n";
    else cout << "c1 == c2\n";



    return 0;

}
