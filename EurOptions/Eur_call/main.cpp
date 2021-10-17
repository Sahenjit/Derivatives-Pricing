//
//  main.cpp
//  Eur_call
//
//  Created by Shankar on 10/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include "Euro_call.hpp"
#include "EurPut.hpp"
#include "StoreFile.hpp"
#include <fstream>
using namespace std;

int main()
{
    double S0=100;
    double r=0.05;
    double T=1.0/12.0;
    double sigma=0.20;
    int no_of_steps=2;
    double K=100;
    double time_step=T/no_of_steps;
    double interest=exp(r*time_step);
    double U=exp((r-pow(sigma,2)/2)*time_step+(0.2*sqrt(time_step)));
    double D=exp((r-pow(sigma,2)/2)*time_step-(0.2*sqrt(time_step)));
    
    
    Storefile s;
    s.Readfile();
    s.Price_port();
}
