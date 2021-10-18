//
//  main.cpp
//  UpandOutEurCall
//
//  Created by Shankar on 19/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>

#include "UpandOutEurCall.hpp"

using namespace std;
int main()
{
    double stock_price=98;
    double strike_price=100;
    double barrier=130;
    double r=0.05;
    double sigma=0.2;
    double t=2;
    double no_of_steps=3;
    double time_step=t/no_of_steps;
    double interest=exp(-r*time_step);
    double U=exp((r-pow(sigma,2)/2)*time_step+(0.2*sqrt(time_step)));
    double D=exp((r-pow(sigma,2)/2)*time_step-(0.2*sqrt(time_step)));
    
    UpandOutEurcall e;
    cout<<"The price of the UpandoutEurcall is: "<<e.PricebyBSFormula(stock_price,strike_price,barrier,r,sigma,t)<<endl;
    cout<<"The price of the option by CRR is: "<<e.PricebyCRR(stock_price,U,D,interest,no_of_steps,strike_price,barrier)<<endl;
   
}
