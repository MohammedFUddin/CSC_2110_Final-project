#include "vehicle.h"

void Car::setVIN(string vin)
{
    VIN = vin;
}
void Car::setMake(string make)
{
    Make = make;
}

void Car::setModel(string model)
{
    Model = model;
}

void Car::setYear(int year)
{
    Year = year;
}

void Car::setPrice(float price)
{
    Price = price;
}

void Car::setCategory(string category)
{
    Category = category;
}

string Car::getVIN()
{
    return VIN;
}

string Car::getMake()
{
    return Make;
}

string Car::getModel()
{
    return Model;
}

int Car::getYear()
{
    return Year;
}

float Car::getPrice()
{
    return Price;
}

string Car::getCategory()
{
    return Category;
}

Car::Car()
{
    VIN = " ";
    Make = " ";
    Model = " ";
    Year = 0;
    Price = 0.0;
    Category = " ";
}

Car::Car(string vin, string make, string model, int year, float price, string category)
{
    VIN = vin;
    Make = make;
    Model =model;
    Year = year;
    Price = price;
    Category = category;
}

void Car:: printInfo() {
    string v, vinN1;
    string Cmake, Cmake1;
    string Carmodel, Carmodel1;
    int y = 0, Cyear1;
    float p = 0.0, Cprice1;
    string c, Ccategory1;
    float mi = 0.0, Cmileage1;
    string CwarrPro, CwarrPro1;
    ifstream usedC("Oldverhicles.txt");
    ifstream advencedC("Newvehicles.txt");
    cout << "\n*** OLD CARS IN OUR INVENTORY ***\n" << endl;
    while (usedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
        cout << vinN1 << " " << Cmake1 << " " << Carmodel1 << " " << Cyear1 << " " << Cprice1 << " " << Ccategory1 << " " << Cmileage1 << " " << CwarrPro1 << endl;
    }
    cout << "\n*** NEW CARS IN OUR INVENTORY ***\n" << endl;
    while (advencedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
        cout << vinN1 << " " << Cmake1 << " " << Carmodel1 << " " << Cyear1 << " " << Cprice1 << " " << Ccategory1 << " " << Cmileage1 << " " << CwarrPro1 << endl;
    }
}
