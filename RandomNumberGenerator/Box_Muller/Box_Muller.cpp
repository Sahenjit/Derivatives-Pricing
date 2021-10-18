//
//  Box_Muller.cpp
//  Box_Muller
//
//  Created by Shankar on 29/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Box_Muller.hpp"
#include <math.h>
#include <random>
#include <iostream>
using namespace std;

void NormalRandomGenerator::generate_z1(double x,double x1)
{
    const double PI=3.141592653589793238463;
    z1=sqrt(-2*log(x))*cos(2*PI*x1);
}
void NormalRandomGenerator::generate_z2(double x,double x1)
{
    const double PI=3.141592653589793238463;
    z2=sqrt(-2*log(x))*sin(2*PI*x1);
}


void NormalRandomGenerator::add_z1()
{
    sum_z1=sum_z1+z1;
    sum_of_squares_z1=sum_of_squares_z1+(pow(z1,2));
    Counter++;
}
void NormalRandomGenerator::add_z2()
{
    sum_z2=sum_z2+z2;
    sum_of_squares_z2=sum_of_squares_z2+(pow(z2,2));
}

double NormalRandomGenerator::mean_z1()
{
    double avg_z1=sum_z1/Counter;
    return avg_z1;
}

double NormalRandomGenerator::mean_z2()
{
    double avg_z2=sum_z2/Counter;
    return avg_z2;
}

double NormalRandomGenerator::stDev_z1()
{
    double variance_z1=(sum_of_squares_z1/Counter)-pow(mean_z1(), 2);
    double st_Dev=sqrt(variance_z1);
    return st_Dev;
}

double NormalRandomGenerator::stDev_z2()
{
    double variance_z2=(sum_of_squares_z2/Counter)-pow(mean_z2(), 2);
    double st_Dev_2=sqrt(variance_z2);
    return st_Dev_2;
}


