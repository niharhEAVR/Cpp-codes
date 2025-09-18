#include<iostream>

class Car {
public:
    int speed;

    void setSpeed(int speed) {
        this->speed = speed;   // use this-> to access current object's member
    }
};


int main() {
    Car car1, car2;

    car1.setSpeed(100);   // inside setSpeed(), this == &car1
    car2.setSpeed(200);   // inside setSpeed(), this == &car2
}