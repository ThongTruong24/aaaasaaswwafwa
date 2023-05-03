/*
 * File: exercise9.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Create a car class and information about maintenance costs, print car information
 */

#include<iostream>
#include<string>

using namespace std;

class Car {
    private:
        string COLOR;
        string ENGINETYPE;
        int KM;
    public:
        Car(string color = NULL, string engineType = NULL, int km = 0);
        int getKm();
        void dataMaintenanceCosts();
        void maintenanceCosts();
           
};

Car::Car (string color, string engineType, int km) {
    this->COLOR = color;
    this->ENGINETYPE = engineType;
    this->KM = km;
}

int Car::getKm() {
    return KM;
}

/* Description: Print repair cost information on the screen */
void Car::dataMaintenanceCosts () {
    cout << "-------------------------------------------------\n";
    cout << "|\tKm\t\t|\tmaintenance fee\t|\n";
    cout << "-------------------------------------------------\n";
    cout << "|\t<5.000\t\t|\t100.000 dong\t|\n";
    cout << "-------------------------------------------------\n";
    cout << "|\t5.000->10.000\t|\t200.000 dong\t|\n";
    cout << "-------------------------------------------------\n";
    cout << "|\t>10.000->50.000\t|\t1.000.000 dong\t|\n";
    cout << "-------------------------------------------------\n";
    cout << "|\t>50.000\t\t|\t4.000.000 dong\t|\n";
    cout << "-------------------------------------------------\n";
}

/* 
 * Function: Car::maintenanceCosts()
 * Description: Calculate the cost with the corresponding number of kilometers
 */
void Car::maintenanceCosts() {

    if (KM < 5000) cout << "\nMaintenance cost: " << "100.000 dong";
    else if(KM >= 5000 & this->KM <=10000) cout << "\nMaintenance cost: " << "200.000 dong";
    else if(KM > 10000 & this->KM <=50000) cout << "\nMaintenance cost: " << "1.000.000 dong";
    else cout << "\nMaintenance cost: " << "4.000.000 dong";

}

int main() {

    Car car("Do", "150cc", 20000);

    car.dataMaintenanceCosts();
    cout << "KM: " << car.getKm();
    car.maintenanceCosts();

}