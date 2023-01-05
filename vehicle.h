#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Car
{
private:
	string VIN;
	string Make;
	string Model;
	int Year;
	float Price;
	string Category;

public: 
	void setVIN(string vin);
	void setMake(string make);
	void setModel(string model);
	void setYear(int year);
	void setPrice(float price);
	void setCategory(string category);
	string getVIN();
	string getMake();
	string getModel();
	int getYear();
	float getPrice();
	string getCategory();
	Car();
	Car(string vin, string make, string model, int year, float price, string category);
	void printInfo();

};

