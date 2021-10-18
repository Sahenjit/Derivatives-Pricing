//
//  Stats1.cpp
//  BSModel
//
//  Created by Shankar on 25/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Stats1.hpp"
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>

using namespace std;

void Stats1:: add(double x)
    {
        sum=sum+x;
        number_of_elements++;
        Sum_of_squares=Sum_of_squares+(x*x);
       
    }
double Stats1:: mean()
{
    
    double average=(sum/number_of_elements);
    return average;
}
double Stats1:: stDev()
{
    double variance=(Sum_of_squares/number_of_elements)-pow(mean(),2);
    double stDev=sqrt(variance);
    return stDev;
    
}

double Stats1::get_number_of_elements()
{
    return number_of_elements++;
}

double Stats1::get_sum()
{
    return sum;
}

