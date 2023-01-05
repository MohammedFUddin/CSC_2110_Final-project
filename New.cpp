#include "New.h"

void advencedCar::setWarrentyProvider(string warrentyprovider)
{
    WarrentyProvider = warrentyprovider;
}

string advencedCar::getWarrentyProvider()
{
    return WarrentyProvider;
}

const float advencedCar::getMileage()
{
    return Mileage;
}

advencedCar::advencedCar()
{
    WarrentyProvider = " ";
    const float Mileage = 0.0;
}

advencedCar::advencedCar(string vin, string make, string model, int year, float price, string category, float mileage, string warrentyprovider) 
    : Car(vin, make, model, year, price, category)
{
    WarrentyProvider = warrentyprovider;
    const float Mileage = mileage;
}