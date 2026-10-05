//1603. Design Parking System

#include <iostream>

using namespace std;

class ParkingSystem 
{
public:
    ParkingSystem(int big, int medium, int small)
    {
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;
    }
    
    bool addCar(int carType) 
    {
        return slots[carType - 1]-- > 0;
    }
    
private:
    int slots[3];
};


int main()
{
    return 0;
}