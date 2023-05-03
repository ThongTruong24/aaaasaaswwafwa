/*
 * File: exercise1.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Calculate the distance of 2 points and the area of ​​3 points
 */

#include<iostream>
#include<stdint.h>
#include<math.h>

using namespace std;

class Point{
    private:
        int8_t XCOORDINATE;
        int8_t YCOORDINATE;
    public:
        Point(int8_t xCoordinate = 0, int8_t yCoordinate = 0);
        int8_t getXCoordinate();
        int8_t getYCoordinate();
};

Point::Point(int8_t xCoordinate, int8_t yCoordinate) {
    this->XCOORDINATE = xCoordinate;
    this->YCOORDINATE = yCoordinate;
}

int8_t Point::getXCoordinate() {
    return XCOORDINATE;
}

int8_t Point::getYCoordinate() {
    return YCOORDINATE;
}


class Distance {
    private:
        Point A;
        Point B;
    public:
        Distance(Point a, Point b);
        double calc();
};

Distance::Distance(Point a, Point b) {
    this->A = a;
    this->B = b;
}

/* 
 * Function: Distance::calc()
 * Description: Calculate distance of 2 points
 * Output:
 *     distance    
 */
double Distance::calc() {
    return sqrt(pow(B.getXCoordinate() - A.getXCoordinate(), 2)
                + pow(B.getYCoordinate() - A.getYCoordinate(), 2));
}

class Acreage {
    private:
        Point A;
        Point B;
        Point C;
    public:
        Acreage(Point a, Point b, Point c);
        double calc();
};

Acreage::Acreage(Point a, Point b, Point c) {
    this->A = a;
    this->B = b;
    this->C = c;
}

/* 
 * Function: Acreage::calc()()
 * Description: Calculate acreage of 2 points
 * Output:
 *     acreage    
 */
double Acreage::calc() {
    double acreage = (abs((B.getXCoordinate() - A.getXCoordinate())
                        *(C.getYCoordinate() - A.getYCoordinate())
                        - (C.getXCoordinate() - A.getXCoordinate())
                        *(B.getYCoordinate() - A.getYCoordinate()))) / 2;
    return acreage;
}



int main(int argc, char const *argv[]) {

    /* Initialize points */
    Point A(18, 6);
    Point B(12, 5);
    Point C(51, 7);
    Point D(60, 12);
    Point E(0, 22);

    Distance distance(A, C);
    cout << "Distance of 2 points: " << distance.calc();
    
    Acreage acreage(A, B, E);
    cout << "\nThe acreage of the triangle made up of 3 points: " << acreage.calc();
}