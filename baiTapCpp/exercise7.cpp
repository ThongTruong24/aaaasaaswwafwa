/*
 * File: exercise7.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Create a class that includes the date, calculate the age and check if it's a holiday
 */

#include<iostream>
#include<stdint.h>
#include<string>
#include <ctime>

using namespace std;

class Time {
    private:
        uint8_t DAY;
        uint8_t MONTH;
        uint16_t YEAR;
    public:
        Time(uint8_t day = 0, uint8_t month = 0, uint16_t year = 0);
        void getYearOld();
        void checkHoliday();
};

Time::Time (uint8_t day, uint8_t month, uint16_t year) {
    this->DAY = day;
    this->MONTH = month;
    this->YEAR = year;
}

/* 
 * Function: Time::getYearOld()
 * Description: Calculate the number of ages based on time functions
 * Ouput:
 *     Age
 */
void Time::getYearOld () {

    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);

    int currentDay = localTime->tm_mday;
    int currentMonth = localTime->tm_mon + 1;
    int currentYear = localTime->tm_year + 1900;

    if (currentMonth > this->MONTH)
        cout << "Year old: " << currentYear - this->YEAR;
    else if (currentMonth = this->MONTH) {
        if (currentDay < this->DAY) cout << "Year old: " << currentYear - this->YEAR - 1;
        else cout << "Year old: " << currentYear - this->YEAR;
    }
    else cout << "Year old: " << currentYear - this->YEAR - 1;
    
}

/* 
 * Function: Time::checkHoliday()
 * Description: cCheck if it's a holiday
 * Ouput:
 *     test information
 */
void Time::checkHoliday () {

    bool holiday1 = (this->DAY == 1) & (this->MONTH == 1);
    bool holiday2 = (this->DAY == 14) & (this->MONTH == 2);
    bool holiday3 = (this->DAY == 8) & (this->MONTH == 3);
    bool holiday4 = (this->DAY == 1 || this->DAY == 2) & (this->MONTH == 5);
    bool holiday5 = (this->DAY == 2) & (this->MONTH == 9);
    /*...*/
    if (holiday1 || holiday2 || holiday3 || holiday4 || holiday5) 
        cout << "\nIt's holiday";
    else cout << "\nIt isn't holiday";

} 

int main() {

    Time time(1, 5, 2003);
    time.getYearOld();
    time.checkHoliday();

}

