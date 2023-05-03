/*
 * File: exercise2.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Calculate the distance of 2 points and the area of ​​3 points
 */

#include<stdio.h>
#include<stdint.h>
#include<math.h>

class Rectangle {
    private:
        uint8_t LENGTH;
        uint8_t WIDTH;
    public:
        Rectangle(uint8_t length = 0, uint8_t width = 0);
        double calcPerimeter();
        double calcAcreage();
        double calcDiagonalLine();
        void checkRectangle();
};

Rectangle::Rectangle (uint8_t length, uint8_t width) {
    this->LENGTH = length;
    this->WIDTH = width;
}

/* 
 * Function: Rectangle::calcPerimeter()
 * Description: Calculate perimeter of the rectangle
 * Output:
 *     perimeter    
 */
double Rectangle::calcPerimeter() {
    return (LENGTH + WIDTH) * 2;
}

/* 
 * Function: Rectangle::calcAcreage()
 * Description: Calculate acreage of the rectangle
 * Output:
 *     acreage    
 */
double Rectangle::calcAcreage() {
    return LENGTH * WIDTH;
}

/* 
 * Function: Rectangle::calcDiagonalLine()
 * Description: Calculate diagonalLine of the rectangle
 * Output:
 *     diagonalLine    
 */
double Rectangle::calcDiagonalLine() {
    return sqrt(pow(LENGTH, 2) + pow(WIDTH, 2));
}

/* 
 * Function: Rectangle::checkRectangle()
 * Description: Check if rectangle is square or not
 */
void Rectangle::checkRectangle() {
    if(LENGTH == WIDTH) printf("It is a square");
    else printf("It is a rectangle");
}

int main(int argc, char const *argv[]) {

    Rectangle rectangle(8, 5);

    printf("Perimeter: %f\n", rectangle.calcPerimeter());
    printf("Acreage: %f\n", rectangle.calcAcreage());
    printf("DiagonalLine: %f\n", rectangle.calcDiagonalLine());
    
    rectangle.checkRectangle();

}
