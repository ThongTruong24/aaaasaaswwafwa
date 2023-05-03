/*
 * File: exercise6.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: 
 * Create a fraction class with numerator and denominator properties and methods
 * formulas to do basic math operations like addition, subtraction, multiplication, and
 * divide
 */

#include<iostream>
#include<stdint.h>

using namespace std;

class Fraction {
    private:
        uint8_t NUMERATOR;
        uint8_t DENOMINATOR;
    public:
        Fraction(uint8_t numerator = 0, uint8_t denominator = 0);
        uint8_t getNumerator();
        uint8_t getDenominator();
};

Fraction::Fraction (uint8_t numerator, uint8_t denominator) {
    this->NUMERATOR = numerator;
    this->DENOMINATOR = denominator;
}

uint8_t Fraction::getNumerator () {
    return NUMERATOR;
}

uint8_t Fraction::getDenominator () {
    return DENOMINATOR;
}


class Calc {
    private:
        Fraction A;
        Fraction B;
    public:
        Calc(Fraction a, Fraction b);
        double getPlus();
        double getSubtract();
        double getMultiply();
        double getDivide();
};

Calc::Calc (Fraction a, Fraction b) {
    this->A = a;
    this->B = b;
}

/* 
 * Function: Calc::getPlus()
 * Description: Plus 2 decimals
 * Ouput:
 *     result
 */
double Calc::getPlus () {
    return (double)A.getNumerator()/(double)A.getDenominator() + 
           (double)B.getNumerator()/(double)B.getDenominator();
}

/* 
 * Function: Calc::getSubtract()
 * Description: Subtract 2 decimals
 * Ouput:
 *     result
 */
double Calc::getSubtract () {
    return (double)A.getNumerator()/(double)A.getDenominator() -
           (double)B.getNumerator()/(double)B.getDenominator();
}

/* 
 * Function: Calc::getMultiply()
 * Description: Multiply 2 decimals
 * Ouput:
 *     result
 */
double Calc::getMultiply () {
    return (double)A.getNumerator()/(double)A.getDenominator() *
           (double)B.getNumerator()/(double)B.getDenominator();
}

/* 
 * Function: Calc::getDivide ()
 * Description: Divide 2 decimals
 * Ouput:
 *     result
 */
double Calc::getDivide () {
    return (double)A.getNumerator()/(double)A.getDenominator() /
           (double)B.getNumerator()/(double)B.getDenominator();
}

int main() {

    Fraction fraction1(2, 3);
    Fraction fraction2(3, 5);

    Calc calc(fraction1, fraction2);
    cout << "Plus: " << calc.getPlus();
    cout << "\nSubtract: " << calc.getSubtract();
    cout << "\nMultiply: " << calc.getMultiply();
    cout << "\nDivide: " << calc.getDivide();
    
}