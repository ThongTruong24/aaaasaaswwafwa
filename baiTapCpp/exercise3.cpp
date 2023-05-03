/*
 * File: exercise3.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: calculate the circumference and area of ​​a circle
 */

#include<stdio.h>
#include<stdint.h>
#include<math.h>

class Circle {
    private:
        uint8_t R;
    public:
        Circle(uint8_t r = 0);
        double calcPerimeter();
        double calcAcreage();
};

Circle::Circle (uint8_t r) {
    this->R = r;
}

/* 
 * Function: Circle::calcPerimeter()
 * Description: Calculate perimeter of the circle
 * Output:
 *     perimeter    
 */
double Circle::calcPerimeter() {
    return 2 * M_PI * R;
}

/* 
 * Function: Circle::calcAcreage
 * Description: Calculate acreage of the circle
 * Output:
 *     acreage   
 */
double Circle::calcAcreage() {
    return M_PI * pow(R, 2);
}

int main(int argc, char const *argv[]) {

    Circle circle(5);

    printf("Perimeter: %f\n", circle.calcPerimeter());
    printf("Acreage: %f\n", circle.calcAcreage());

}
