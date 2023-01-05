#include "Old.h"
class advencedCar :
    public Car
{
private:
    string WarrentyProvider;
    const float Mileage = 0.0;
public:
    void setWarrentyProvider(string warrentyprovider);
    string getWarrentyProvider();
    const float getMileage();
    advencedCar();
    advencedCar(string vin, string make, string model, int year, float price, string category, float mileage, string warrentyprovider);
};
