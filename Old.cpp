#include "Old.h"

void usedCar::setMileage(float mileage)
{
    Mileage = mileage;
}

float usedCar::getMileage()
{
    return Mileage;
}

usedCar::usedCar()
{
    Mileage = 0.0;
}
usedCar::usedCar(string vin, string make, string model, int year, float price, string category, float mileage): 
    Car(vin, make, model, year, price, category)
{
    Mileage = mileage;
}

