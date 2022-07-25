<!-- PROJECT LOGO -->
<h1 align="center">Real-Time Intelligent Car</h1>
<p align="center">
<br/>
<p align="center">
<img src="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/logo.png" width="300" height="300">
  </p>
<br/>

<p align="center">
    <a href="https://www.youtube.com/watch?v=-Maqk7YZIQ4" alt="Contributors">
        <img src="https://upload.wikimedia.org/wikipedia/commons/0/09/YouTube_full-color_icon_%282017%29.svg" height="40" width="40"/></a>
    <a href="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/LICENSE" alt="License">
        <img src="https://upload.wikimedia.org/wikipedia/commons/e/e7/Instagram_logo_2016.svg" height="40" width="40" /></a>
</p>

<p align="center">
    <a href="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/graphs/contributors" alt="Contributors">
        <img src="https://img.shields.io/badge/Contributors%20-4-brightgreen.svg?style=flat-square" /></a>
    <a href="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/LICENSE" alt="License">
        <img src="https://img.shields.io/github/license/Maripoforest/GestureHueLight.svg?color=red" /></a>
    <a href="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/releases" alt="Tag">
        <img src="https://img.shields.io/github/v/release/Maripoforest/GestureHueLight?color=pink" alt="build status"></a>
</p>

____________________________________________________________________________________________________________________________________________________________________
## Contents
<ul>
    <li><a href="#Introduction">Introduction</a>
        <ul>
            <li><a href="#Schedule">Schedule</a>
            <li><a href="#Hardware">Hardware</a>
            <li><a href="#Processflow">Processflow</a>
        </ul>
    <li><a href="#Guidance">Guidance</a>
        <ul>
            <li><a href="#QT Creator">QT Creator</a>
            <li><a href="#Test">Test</a>
            <li><a href="#Static Library">Static Library</a>
        </ul>
    <li><a href="#Authors">Authors</a>
</ul>

# Introduction

The advancement of society and technology has made the world pay more attention to environmental issues, and the trend of electric motors to replace traditional mechanical engines has become more and more clear. Meanwhile, the automation of driving has also become an important part of this technological revolution. This includes the large-scale industrial platforms of automobile companies but also the needs of individuals for motor vehicles to complete small daily life tasks. Under this demand, we have developed a motor-driven trolley on a semi-mature hardware platform using C++ language and I2C is used as the communication protocol which can be remotely controlled and can be equipped with various expansion devices. The application field can be production activities such as site management.

Our team‘s project is to design an Intelligent car that can be controlled movement in real time. In the aspect of installation we chose Freenove 4wd Car. We can save time to buy the corresponding accessories directly, installation teaching video is shown below: https://www.youtube.com/watch?v=G3Q8xNatXgM

This code is mainly divided into two parts: one is the code for raspberry PI to control the car's movement; the other is the code for raspberry PI to be remotely controlled by electronic devices. 

In the car's movement part, we will use the driver board PCA9685. It was originally designed to control multi-channel LED, but later people found its has great advantage in controlling multi-channel motor, so it gradually became the drive board to control motor.  We plan to use PCA9685 to control all four motors on the wheels of the car. Then we'll use the I2C protocol, I2C is the short for Inter-Integrated Circuit. It allows two-line serial data transmission mode and is mainly used for the connection between integrated circuit modules (IC) on the same circuit board. In terms of hardware, I2C bus only needs one data line and one clock line. The bus interface has already been integrated in the raspberry PI, without special interface circuit. So it's very stable and economical. Its main purpose is to communicate between the SOC and surrounding devices such as sensors. In our Intelligent car project, we will use I2C communication protocol and raspberry PI to control PCA9685, so as to achieve the car forward, backward, stop, left and right turn and other actions.  

In remote control, we decided to use QT software and socket communication protocol, which can achieve the connection between the server and the client, and data transmission. Sockets are at the transport layer of network protocols. There are two protocols: TCP and UDP and in this work we use TCP protocol. We will also design a visual graphical interface, including forward, backward, stop, left and right turn all buttons, of course, it also including the connect and disconnect buttons, this is our attempt to move towards human-computer friendly direction.  

In addition, we added the motor test code. we also added some command to determine whether the connection is successful in socket part, if not, it will prompt unsucessful, so as to determine whether the connection is successful. After each part of the test is passed, we put these functions together to realize the real-time control of the smart car.


## Schedule

<p align="center">
<img src="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/Timetable(GANNT%20Chatt).png" width="850" height="350">
  </p>
<br/>

## Hardware

• Raspberry Pi 4 <br/>
• Freenove Car Develop Kit <br/>
• 5V/3A power adapter <br/>
• Micro SD card and reader <br/>
• 3.7V 18650 batteries <br/>

## Processflow
<p align="center">
<img src="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/Processflow.png" width="600" height="800">
  </p>
<br/>

# Guidance

## QT Creator
In this project, we download QT creator Software on Windows to design the GUI for controlling the mini car remotely. It’s important to create and connect **_sockets_** to send data in a network. With the IP address and port of Raspberry Pi, we can establish connection between server and client by TCP protocol. 

  </p>
<br/>
After running the "client" project in QT Creator Software, the UI design is shown below. Once we click the connect button, the "off" on the screen will change to “connect successful” and now we can control the mini car！
 </p>
<br/>
<p align="center">
<img src="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/mainwindow.png" width="250" height="250">
  </p>
<br/>

## Test

### 1. How to test code on Raspberry through Terminal console
```
cd ~/smartcar  
g++ pca9685.cpp -lwiringPi -o pcatest
./pcatest     
```
##### (smartcar is the folder where cpp files exist, the second line is to compile the pca9685.cpp with the aid of wiringPi library and generate a executable file called pcatest and the third line is to execute the pcatest in the same path）

### 2. The test of motor is similar with the previous step:
```
cd ~/smartcar   
g++ motor.cpp -lwiringPi -o motortest
./motortest     
```
##### (The second line is to compile the motor.cpp with the aid of wiringPi library and generate a executable file called motortest, the third line is to execute the motortest in the same path)

## Static Library

### 1. How to generate the Static library
```
cd ~/smartcar   
g++ pca9685.cpp -lwiringPi -o pca9685.o 
ar rcs libpca9685.a pca9685.o
```
##### (First line is to jump to the folder and second line is to compile the pca9685.cpp with the aid of wiringPi then generate a .o file called pca9685.o. Third line is to use the .o file to generate a static library)

### 2. The generation of motor’s static library is similar with the previous code
```
cd ~/smartcar   
g++ motor.cpp -lwiringPi -o motor.o 
ar rcs libmotor.a motor.o 
```

### 3. How to use the static library
```
cd ~/smartcar   
g++ motor.cpp -lwiringPi -lpca9685 -L ./ -o motortest 
```
##### (The first line is to complie the motor.cpp with the aid of wiringPi and the static library which generated from pca9685, because the motor file is built based on it. “-L ./” means use the library in the same path with the cpp file.)

### 4. Function of the static library
##### Without the static library, the compiler cannot detect the header file as well as the functions in it. By using static library, the coder can relate two code file together and achieve cross compilation.


## Authors:

* <a href="https://github.com/PhillipsSong3">Zhengqi Song</a> <br/>
* <a href="https://github.com/dimitrithewalker">Dong Chen</a> <br/>
* Yike Hu</a> <br/>
* Peng Jiang</a> <br/>



