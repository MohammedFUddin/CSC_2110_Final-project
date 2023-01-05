#include "vehicle.h"
class usedCar :
    public Car
{
private:
    float Mileage;
public:
    void setMileage(float mileage);
    float getMileage();
    usedCar();
    usedCar(string vin, string make, string model, int year, float price, string category, float mileage);
};
