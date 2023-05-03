/*
 * File: exercise5.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Human information management
 */

#include<iostream>
#include<string>
#include <ctime>

using namespace std;

class Human {
    private:
        string NAME;
        string ADDRESS;
        int YEAR;
    public:
        Human(string Name = NULL, string address = NULL, int year = 0);
        void getInformation();
        void getYearOld();
};

Human::Human (string name, string address, int year) {
    this->NAME = name;
    this->ADDRESS = address;
    this->YEAR = year;
}

void Human::getInformation () {
    cout << "Name: " << this->NAME << "\n";
    cout << "Address: " << this->ADDRESS << "\n";
    cout << "Year old: " << this->YEAR << "\n";
}

/* 
 * Function: Human::getYearOld()()
 * Description: Use time functions to calculate age
 * Input:
 * Ouput:
 *     print year old
 */
void Human::getYearOld() {

    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    int year = localTime->tm_year + 1900;

    cout << "Year old: " << year - this->YEAR;
}

int main() {

    Human human("Thong", "Quang Ngai", 2003);
    human.getInformation();
    human.getYearOld();

}


