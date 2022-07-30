#include "pca9685.h"
#include "motor.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <unistd.h>



using namespace std;
bool pwm;

class Motor {
public:
    bool MotorInit()
    {

        PCA9685SetPwmFreq(50); //Set Pwm frequency
        return 0;
    }

    int DutyRange(int duty1, int duty2, int duty3, int duty4)
    {
        if (duty1 > 4095) //limit the maximum value to 4095
        {
            duty1 = 4095;
        }
        else if (duty1 < -4095)
        {
            duty1 = -4095;  //limit the maximum value to 4095
        }

        if (duty2 > 4095)
        {
            duty2 = 4095;
        }
        else if (duty2 < -4095)
        {
            duty2 = -4095;
        }

        if (duty3 > 4095)
        {
            duty3 = 4095;
        }
        else if (duty3 < -4095)
        {
            duty3 = -4095;
        }

        if (duty4 > 4095)
        {
            duty4 = 4095;
        }
        else if (duty4 < -4095)
        {
            duty4 = -4095;
        }
        return duty1;
        return duty2;
        return duty3;
        return duty4;
    }

    void left_upper_wheel(int duty)  // set left_upper wheel
    {
        if (duty > 0)
        {
            PCA9685SetMotorPwm(0, 0);
            PCA9685SetMotorPwm(1, duty);
        }
        else if (duty < 0)
        {
            PCA9685SetMotorPwm(1, 0);
            PCA9685SetMotorPwm(0, abs(duty));
        }
        else {
            PCA9685SetMotorPwm(0, 4095);
            PCA9685SetMotorPwm(1, 4095);
        }
    }

    void left_lower_wheel(int duty) // set left_lower wheel
    {
        if (duty > 0)
        {
            PCA9685SetMotorPwm(3, 0);
            PCA9685SetMotorPwm(2, duty);
        }
        else if (duty < 0)
        {
            PCA9685SetMotorPwm(2, 0);
            PCA9685SetMotorPwm(3, abs(duty));
        }
        else {
            PCA9685SetMotorPwm(2, 4095);
            PCA9685SetMotorPwm(3, 4095);
        }
    }

    void right_upper_wheel(int duty) // set right_upper wheel
    {
        if (duty > 0)
        {
            PCA9685SetMotorPwm(6, 0);
            PCA9685SetMotorPwm(7, duty);
        }
        else if (duty < 0)
        {
            PCA9685SetMotorPwm(7, 0);
            PCA9685SetMotorPwm(8, abs(duty));
        }
        else {
            PCA9685SetMotorPwm(6, 4095);
            PCA9685SetMotorPwm(7, 4095);
        }
    }

    void right_lower_wheel(int duty) // set right_lower wheel
    {
        if (duty > 0)
        {
            PCA9685SetMotorPwm(4, 0);
            PCA9685SetMotorPwm(5, duty);
        }
        else if (duty < 0)
        {
            PCA9685SetMotorPwm(5, 0);
            PCA9685SetMotorPwm(4, abs(duty));
        }
        else {
            PCA9685SetMotorPwm(4, 4095);
            PCA9685SetMotorPwm(5, 4095);
        }
    }

    void SetMotorMode1(int duty1, int duty2, int duty3, int duty4) //set the speed of the motor
    {
        DutyRange(duty1, duty2, duty3, duty4);
        left_upper_wheel(duty1);
        left_lower_wheel(duty2);
        right_upper_wheel(duty3);
        right_lower_wheel(duty4);
    }
};
// Motor m_up;
// Motor m_down;
// Motor m_left;
// Motor m_right;
// Motor m_stop;

