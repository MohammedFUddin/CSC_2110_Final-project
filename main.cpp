#include <iostream>
using namespace std;
#include "New.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

int Menu() {
    cout << "\nABC Car Dealership!" << endl;
    cout << setw(30) << setfill('-') << "" << endl;
    cout << "Select the option you want:" << endl;
    cout << "1. Search Inventory" << endl;
    cout << "2. Sell/Lease Cars" << endl;
    cout << "3. Return a Leased Car" << endl;
    cout << "4. Add Cars to Inventory" << endl;
    cout << "5. Exit" << endl;
    cout << "\nEnter a Number Here Please: ";
    int x;
    cin >> x;
    return x;
}


void Search(int x) {
    ifstream usedC("oldvehicles.txt");
    ifstream advencedC("Newvehicles.txt");
    string line;
    string v, vinN1, Cmake, Cmake1, Carmodel, Carmodel1, c, Ccategory1, CwarrPro, CwarrPro1;
    int y, Cyear1;
    float p = 0.0, Cprice1, mi = 0.0, Cmileage1;
    Car car1;
    advencedCar advencedCar1;
    size_t pos;
    int count = 0;
    if (x == 1) {

        cout << "\nEnter: ";
        cin >> Cmake;
        transform(Cmake.begin(), Cmake.end(), Cmake.begin(), ::toupper);
        car1.setMake(Cmake);

        while (usedC.good()) {
            getline(usedC, line);
            pos = line.find(car1.getMake());
            if (pos != string::npos) {
                cout << line << endl;
                count++;
            }
            else if (advencedC.good()) {
                getline(advencedC, line);
                pos = line.find(car1.getMake());
                if (pos != string::npos) {
                    cout << line << endl;
                    count++;
                }
            }
        }
        if (count == 0) {
            cout << "\nUnfortunatly we don't have any car for this make" << endl << endl;
        }
        advencedC.close();
        usedC.close();
    }
    else if (x == 2) {
            float loCwarrPror, highpr;
            cout << "\nEnter the lowest price point: $";
            cin >> loCwarrPror;
            cout << "Enter the highest price point: $";
            cin >> highpr;
            while (usedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1 || advencedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
                if (loCwarrPror <= Cprice1 && highpr >= Cprice1) {
                    usedCar usedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1);
                    advencedCar advencedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1, CwarrPro1);
                    cout << advencedCar2.getVIN() << " " << advencedCar2.getMake() << " " << advencedCar2.getModel() << " " << advencedCar2.getYear() << " " << advencedCar2.getPrice() << " " << advencedCar2.getCategory()
                        << " " << advencedCar2.getMileage() << " " << advencedCar2.getWarrentyProvider() << endl;
                    count++;
                }
            
            }
        if (count == 0) {
            cout << "\nUnfortunatly we don't have any car for this price" << endl << endl;
        }
        advencedC.close();
        usedC.close();
    }
}

void Search() {
    cout << "\nHow would you like to search for a car?" << endl;
    cout << "1. Look for the car by it's Make" << endl;
    cout << "2. Look for the car by it's Model" << endl;
    cout << "3. Look for the car by it's Price" << endl;
    cout << "4. Look for the car by it's Category" << endl;
    int SearchEntry;
    cout << "\nEnter a Number Here Please: ";
    cin >> SearchEntry;
    switch (SearchEntry) {
    case 1:
    case 2:
    case 4:
        Search(1);
        break;
    case 3:
        Search(2);
        break;
    }
}


void SellOrLease() {
    cout << "How do you want to make a purchase?" << endl;
    cout << "1. Sell a Car" << endl;
    cout << "2. Lease a Car" << endl;
    cout << "\nEnter a Number Here Please: ";
    int sellorlease;
    cin >> sellorlease;
    switch (sellorlease) {
    case 1:
        cout << "\nAre you selling new or old car?" << endl;
        cout << "1. New Car" << endl;
        cout << "2. Old Car" << endl;
        cout << "\nEnter a Number Here Please: ";
        int sellNewcOldc;
        cin >> sellNewcOldc;
        if (sellNewcOldc == 1) {
            ifstream advencedC;
    string path2 = "Newvehicles.txt";
    advencedC.open(path2);
    string line;
    ofstream temporary2("temporary2.txt");
    string v, vinN1;
    string Cmake, Cmake1;
    string Carmodel, Carmodel1;
    int y, Cyear1;
    float p = 0.0, Cprice1;
    string c, Ccategory1;
    float mi = 0.0, Cmileage1;
    string CwarrPro, CwarrPro1;
    int count = 0;
    cout << "\nType the vin number: ";
    cin >> v;
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    while (advencedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
        if (v == vinN1) {
            count++;
        }
        if (v != vinN1) {
            advencedCar advencedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1, CwarrPro1);
            temporary2 << advencedCar2.getVIN() << " " << advencedCar2.getMake() << " " << advencedCar2.getModel() << " " << advencedCar2.getYear() << " " << advencedCar2.getPrice() << " " << advencedCar2.getCategory()
                << " " << advencedCar2.getMileage() << " " << "NA" << endl;
        }
    }
    if (count == 0) {
        cout << "\nUnfortunatly we don't have any car for this vin" << endl << endl;
    }
    else {
        cout << "\ncar sold" << endl;
    }
    temporary2.close();
    advencedC.close();
    const char* z2 = path2.c_str();
    remove(z2);
    rename("temporary2.txt", z2);
        }
        else if (sellNewcOldc == 2) {
            ifstream usedC;
    string path = "oldvehicles.txt";
    usedC.open(path);
    string line;
    ofstream temporary("temporary.txt");
    string v, vinN1;
    string Cmake, Cmake1;
    string Carmodel, Carmodel1;
    int y = 0, Cyear1;
    float p = 0.0, Cprice1;
    string c, Ccategory1;
    float mi = 0.0, Cmileage1;
    string CwarrPro, CwarrPro1;
    int count = 0;
    cout << "\nEnter the vin number: ";
    cin >> v;
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    while (usedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
        if (v == vinN1) {
            count++;
        }
        else if (v != vinN1) {
            usedCar usedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1);
            //advencedCar advencedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1, CwarrPro1);
            temporary << usedCar2.getVIN() << " " << usedCar2.getMake() << " " << usedCar2.getModel() << " " << usedCar2.getYear() << " " << usedCar2.getPrice() << " " << usedCar2.getCategory()
                << " " << usedCar2.getMileage() << " " << "NA" << endl;
        }
    }
    if (count == 0) {
        cout << "\nUnfortunatly we don't have any car for this vin" << endl << endl;
    }
    else {
        cout << "\ncar sold" << endl;
    }


    temporary.close();
    usedC.close();

    const char* z = path.c_str();
    remove(z);
    rename("temporary.txt", z);
        }
        break;
    case 2:
    ifstream advencedC;
    string path = "Newvehicles.txt";
    advencedC.open(path);
    ofstream temporary("temporary.txt");
    ofstream outLease;
    ifstream inLease;
    inLease.open("leasedvehicles.txt");
    outLease.open("leasedvehicles.txt", ios::app);
    string v, vinN1;
    string Cmake, Cmake1;
    string Carmodel, Carmodel1;
    int y = 0, Cyear1;
    float p = 0.0, Cprice1;
    string c, Ccategory1;
    float mi = 0.0, Cmileage1;
    string CwarrPro, CwarrPro1;
    int count = 0;
    cout << "\nEnter the vin number: ";
    cin >> v;
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    while (advencedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
        if (v == vinN1) {
            advencedCar advencedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1, CwarrPro1);
            if (inLease.is_open()) {
                outLease << advencedCar2.getVIN() << " " << advencedCar2.getMake() << " " << advencedCar2.getModel() << " " << advencedCar2.getYear() << " " << advencedCar2.getPrice() << " " << advencedCar2.getCategory()
                    << " " << advencedCar2.getMileage() << " " << "NA" << endl;
                
            }
            count++;
        }

        else if (v != vinN1) {

            advencedCar advencedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1, CwarrPro1);
            temporary << advencedCar2.getVIN() << " " << advencedCar2.getMake() << " " << advencedCar2.getModel() << " " << advencedCar2.getYear() << " " << advencedCar2.getPrice() << " " << advencedCar2.getCategory()
                << " " << advencedCar2.getMileage() << " " << "NA" << endl;
        }
    }

    if (count == 0) {
        cout << "\nUnfortunatly we don't have any car for this vin" << endl << endl;
    }
    else {
        cout << "car leased" << endl;
    }
    
    inLease.close();
    outLease.close();
    temporary.close();
    advencedC.close();


    const char* z = path.c_str();
    remove(z);
    rename("temporary.txt", z);
        break;
    }
}




void returnLeasedCar() {
    ifstream Leasedcars;
    string path = "leasedvehicles.txt";
    Leasedcars.open(path);
    string line;
    ofstream temporary("temporary.txt");
    ofstream outReturn;
    ifstream inReturn;
    inReturn.open("oldvehicles.txt");
    outReturn.open("oldvehicles.txt", ios::app);
    string v, vinN1;
    string Cmake, Cmake1;
    string Carmodel, Carmodel1;
    int y = 0, Cyear1;
    float p = 0.0, Cprice1;
    string c, Ccategory1;
    float mi = 0.0, Cmileage1;
    string CwarrPro, CwarrPro1;
    int count = 0;
    cout << "\nEnter the vin number: ";
    cin >> v;
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    while (Leasedcars >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {

        if (inReturn.is_open()) {
                if (v == vinN1) {
                    usedCar usedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1);
                    advencedCar advencedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1, CwarrPro1);


                    outReturn << advencedCar2.getVIN() << " " << advencedCar2.getMake() << " " << advencedCar2.getModel() << " " << advencedCar2.getYear() << " " << advencedCar2.getPrice() << " " << advencedCar2.getCategory()
                        << " " << mi << " " << advencedCar2.getWarrentyProvider() << endl;
                    inReturn.close();
                    outReturn.close();
                    count++;
                    cout << "Car returned completed" << endl;
                }
            else if (v != vinN1) {
                usedCar usedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1);
                advencedCar advencedCar2(vinN1, Cmake1, Carmodel1, Cyear1, Cprice1, Ccategory1, Cmileage1, CwarrPro1);
                temporary << usedCar2.getVIN() << " " << usedCar2.getMake() << " " << usedCar2.getModel() << " " << usedCar2.getYear() << " " << usedCar2.getPrice() << " " << usedCar2.getCategory()
                    << " " << usedCar2.getMileage() << " " << "NA" << endl;
            }


        }

    }
    if (count == 0) {
        cout << "WRONG VIN" << endl << endl;
    }



    temporary.close();
    Leasedcars.close();


    const char* z = path.c_str();
    remove(z);
    rename("temporary.txt", z);
}



// ADD FUNCTION


void AddCar() {
    cout << "\nAre you adding a new or an old car?" << endl;
    cout << "1. New Car" << endl;
    cout << "2. Old Car" << endl;
    cout << "\nEnter a number Please: ";
    int a;
    cin >> a;
    if (a == 1){
    ifstream usedC("oldvehicles.txt");
    ifstream advencedC("Newvehicles.txt");
    string line;
    ofstream outLease;
    ifstream inLease;
    inLease.open("Newvehicles.txt");
    outLease.open("Newvehicles.txt", ios::app);
    string v, vinN1;
    string Cmake, Cmake1;
    string Carmodel, Carmodel1;
    int y = 0, Cyear1;
    float p = 0.0, Cprice1;
    string c, Ccategory1;
    float mi = 0.0, Cmileage1;
    string CwarrPro, CwarrPro1;
    int count = 0;
    cout << "Enter the vin number: ";
    cin >> v;
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    while (usedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1 || advencedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
        if (v == vinN1) {
            cout << "We already have the same car in out Inventory" << endl;
            exit(1);
    }
}
    cout << "Enter Make: ";
    cin >> Cmake;
    transform(Cmake.begin(), Cmake.end(), Cmake.begin(), ::toupper);
    cout << "Enter Model: ";
    cin >> Carmodel;
    transform(Carmodel.begin(), Carmodel.end(), Carmodel.begin(), ::toupper);
    cout << "Enter Year: ";
    cin >> y;
    cout << "Enter Price: ";
    cin >> p;
    cout << "Enter Category: ";
    cin >> c;
    transform(c.begin(), c.end(), c.begin(), ::toupper);
    cout << "Mileage of a new car is 0.0 from manufucturer" << endl;
    float dmi = 0.0;
    cout << "Enter Warrenty Provider: ";
    cin >> CwarrPro;
    transform(CwarrPro.begin(), CwarrPro.end(), CwarrPro.begin(), ::toupper);
        if (inLease.is_open()) {
            outLease << v << " " << Cmake << " " << Carmodel << " " << y << " " << p << " " << c
                << " " << dmi << " " << CwarrPro << endl;
            inLease.close();
            outLease.close();
        }
        cout << "\nCar added completed" << endl;    
    
    }
    else if (a == 2){
        ifstream usedC("oldvehicles.txt");
    ifstream advencedC("Newvehicles.txt");
    string line;
    ofstream outLease;
    ifstream inLease;
    inLease.open("oldvehicles.txt");
    outLease.open("oldvehicles.txt", ios::app);
    string v, vinN1;
    string Cmake, Cmake1;
    string Carmodel, Carmodel1;
    int y = 0, Cyear1;
    float p = 0.0, Cprice1;
    string c, Ccategory1;
    float mi = 0.0, Cmileage1;
    string CwarrPro, CwarrPro1;
    int count = 0;
    cout << "Enter the vin number: ";
    cin >> v;
    transform(v.begin(), v.end(), v.begin(), ::toupper);
    while (usedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1 || advencedC >> vinN1 >> Cmake1 >> Carmodel1 >> Cyear1 >> Cprice1 >> Ccategory1 >> Cmileage1 >> CwarrPro1) {
        if (v == vinN1) {
            cout << "We already have the same car in out Inventory" << endl;
            exit(1);
        }
    }
    cout << "Enter Make: ";
    cin >> Cmake;
    transform(Cmake.begin(), Cmake.end(), Cmake.begin(), ::toupper);
    cout << "Enter Model: ";
    cin >> Carmodel;
    transform(Carmodel.begin(), Carmodel.end(), Carmodel.begin(), ::toupper);
    cout << "Enter Year: ";
    cin >> y;
    cout << "Enter Price: ";
    cin >> p;
    cout << "Enter Category: ";
    cin >> c;
    transform(c.begin(), c.end(), c.begin(), ::toupper);
    cout << "Enter Mileage: ";
    cin >> mi;
    cout << "Warranty provider for old car is not applicable!" << endl;
    string dCwarrPro = "NA";
    if (inLease.is_open()) {
        outLease << v << " " << Cmake << " " << Carmodel << " " << y << " " << p << " " << c
            << " " << mi << " " << dCwarrPro << endl;
        inLease.close();
        outLease.close();
    }
    cout << "\nCar added completed" << endl;
    }

}

int main()
{
    int Entry = Menu();
    while (Entry != 5) {
        switch (Entry) {
                case 1:
            Search();
            break;
        case 2:
            SellOrLease();
                break;
        case 3:
            returnLeasedCar();
            break;
        case 4:
            AddCar();
            break;
        }
        Entry = Menu();
    }
}
