<!-- PROJECT LOGO -->
<h1 align="center">Real-Time Intelligent Car</h1>
<p align="center">
<br/>
<p align="center">
<img src="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/logo.png" width="300" height="300">
  </p>
<br/>

<p align="center">
    <a href="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/graphs/contributors" alt="Contributors">
        <img src="https://upload.wikimedia.org/wikipedia/commons/0/09/YouTube_full-color_icon_%282017%29.svg" height="40" width="40"/></a>
    <a href="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/LICENSE" alt="License">
        <img src="https://upload.wikimedia.org/wikipedia/commons/e/e7/Instagram_logo_2016.svg" height="40" width="40" /></a>
    <a href="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/LICENSE" alt="License">
        <img src="https://en.wikipedia.org/wiki/File:Bilibili_logo.svg" height="40" width="50" /></a>
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
            <li><a href="#Components">Components</a>
            <li><a href="#Processflow">Processflow</a>
            <li><a href="#Functions">Functions</a>
        </ul>
    <li><a href="#Quick start">Quick start</a>
        <ul>
            <li><a href="#Connect-hardware">Connect hardware</a>
            <li><a href="#Installation">Installation</a>
            <li><a href="#Test">Test</a>
            <li><a href="#Static Library">Static Library</a>
        </ul>
    <li><a href="#Authors">Authors</a>
</ul>

## Introduction

The advancement of society and technology has made the world pay more attention to environmental issues, and the trend of electric motors to replace traditional mechanical engines has become more and more clear. Meanwhile, the automation of driving has also become an important part of this technological revolution. This includes the large-scale industrial platforms of automobile companies but also the needs of individuals for motor vehicles to complete small daily life tasks. Under this demand, we have developed a motor-driven trolley on a semi-mature hardware platform using C and C++ language which can be remotely controlled and can be equipped with various expansion devices. The application field can be production activities such as site management.


## Schedule

<p align="center">
<img src="https://github.com/PhillipsSong3/Real-Time_Intelligent_Car/blob/main/Timetable(GANNT%20Chatt).png" width="850" height="350">
  </p>
<br/>

## Components

• Raspberry Pi 4 <br/>
• C/C++ Language for embedded-coding <br/>
• Freenove Car Develop Kit <br/>
• 5V/3A power adapter <br/>
• Micro SD card and reader <br/>
• 3.7V 18650 batteries <br/>

## Processflow

## Functions
Free control of intelligent car,Remote control car wireless.

## Quick start

## Connect-hardware

## Installation

## Test

### 1. How to test code on Raspberry through Terminal console
```
cd ~/smartcar  
g++ pca9685.cpp -lwiringPi -o pcatest// compile the pca9685.cpp with the aid of wiringPi library and generate a executable file called pcatest
./pcatest     
```
##### (smartcar is the folder where cpp files exist and the third line is to execute the pcatest in the same path）

### 2. The test of motor is similar with the previous step:
```
cd ~/smartcar   
g++ motor.cpp -lwiringPi -o motortest// compile the motor.cpp with the aid of wiringPi library and generate a executable file called motortest
./motortest     
```
##### (the third line is to execute the motortest in the same path)

## Static Library

### 1. How to generate the Static library
```
cd ~/smartcar   //jump to the folder
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



