#include <iostream>
#include "pca9685.h"
#include "motor.h"
#include "pca9685.cpp"
#include "motor.cpp"

using namespace std;

Motor m1;
void test_motor() {
    cout << "test starts---------" << endl;
    cout << "The car is moving forward---------" << endl;
    m1.SetMotorMode1(2000, 2000, 2000, 2000);       //Forward
    usleep(1000);
    cout << "The car is moving backwards--------" << endl;
    m1.SetMotorMode1(-2000, -2000, -2000, -2000);   //Back
    usleep(1000);
    cout << "The car is going left--------" << endl;
    m1.SetMotorMode1(-500, -500, 2000, 2000);      //Left
    usleep(1000);
    cout << "The car is going right--------" << endl;
    m1.SetMotorMode1(2000, 2000, -500, -500);      //Right
    usleep(1000);
    cout << "The car stops--------" << endl;
    m1.SetMotorMode1(0, 0, 0, 0);            // Stop
    cout << "test ends------------" << endl;
}
