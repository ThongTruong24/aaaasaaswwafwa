/*
 * File: exercise4.cpp
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Calculate BMI of people, compare height and weight
 */

#include<iostream>
#include<string>

using namespace std;
class Human {
    private:
        string NAME;
        double HEIGHT;
        double WEIGHT;
    public:
        Human(string name = NULL, double height = 0, double weight = 0);
        string getName();
        double getHeight();
        double getWeight();
        double getBMI();
};

Human::Human(string name, double height, double weight) {
    this->NAME = name;
    this->HEIGHT = height;
    this->WEIGHT = weight;
}

string Human::getName() {
    return NAME;
}

double Human::getHeight() {
    return HEIGHT;
}

double Human::getWeight() {
    return WEIGHT;
}

double Human::getBMI() {
    return WEIGHT/(HEIGHT*HEIGHT);
}

class Compare {
    public:
        void compareHeight(Human humanA, Human humanB);
        void compareWeight(Human humanA, Human humanB);
};

/* 
 * Function: Compare::compareHeight()
 * Description: Compare the height of 2 people with each other
 * Input:
 *     Human humanA
 *     Human humanB
 * Ouput:
 *     print comparison results
 */
void Compare::compareHeight(Human humanA, Human humanB) {

    if (humanA.getHeight() > humanB.getHeight())
        cout << humanA.getName() << " is higher than " << humanB.getName() << "\n";
    else if (humanA.getHeight() < humanB.getHeight()) 
        cout << humanB.getName() << " is higher than " << humanA.getName() << "\n";
    else cout << "Same height";  
}                      

/* 
 * Function: Compare::compareWeight()
 * Description: Compare the weight of 2 people with each other
 * Input:
 *     Human humanA
 *     Human humanB
 * Ouput:
 *     print comparison results
 */
void Compare::compareWeight(Human humanA, Human humanB) {

    if (humanA.getWeight() > humanB.getWeight())
        cout << humanA.getName() << " is heavier than " << humanB.getName() << "\n";
    else if (humanA.getWeight() < humanB.getWeight())
        cout << humanB.getName() << " is heavier than " << humanA.getName() << "\n";
    else cout << "Same weight";
}                      

int main(int argc, char const *argv[]) {
    
    Human human1("Toan", 1.67, 60.2);
    cout << human1.getName() << "'s BMI: " << human1.getBMI();
    
    Human human2("An", 1.87, 59.2);
    cout << "\n" << human2.getName() << "'s BMI: " << human2.getBMI() << "\n\n";

    Compare compare;
    compare.compareHeight(human1, human2);
    compare.compareWeight(human1, human2);

}