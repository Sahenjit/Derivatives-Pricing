//
//  EurOption.cpp
//  Eur_call
//
//  Created by Shankar on 10/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "EurOption.hpp"

using namespace std;

EurOption::EurOption()
{
    T_=0;
    K_=0;
}
EurOption::EurOption(double K_,double T_)
{
    this->T_=T_;
    this->K_=K_;
}
double EurOption::N(double x)
{
    double gamma = 0.2316419;     double a1 = 0.319381530;
    double a2    =-0.356563782;   double a3 = 1.781477937;
    double a4    =-1.821255978;   double a5 = 1.330274429;
    double pi    = 4.0*atan(1.0); double k  = 1.0/(1.0+gamma*x);
    if (x>=0.0)
        {
            return 1.0-((((a5*k+a4)*k+a3)*k+a2)*k+a1)*k*exp(-x*x/2.0)/sqrt(2.0*pi);
        }
           else return 1.0-N(-x);
}
double EurOption::d_plus(double S0,double sigma,double r)
{
    return (log(S0/K_)+(r+0.5*pow(sigma,2.0))*T_)/(sigma*sqrt(T_));
}
double EurOption::d_minus(double S0, double sigma, double r)
{
          return d_plus(S0,sigma,r)-sigma*sqrt(T_);
}
double EurOption::VegaByBSFormula(double S0,double sigma,double r)
{
       double pi=4.0*atan(1.0);
       return S0*exp(-d_plus(S0,sigma,r)*d_plus(S0,sigma,r)/2)*sqrt(T_)/sqrt(2.0*pi);
}
double EurOption::stock_movement(double stock_price, double U, double D, int no_of_steps, int i)
{
    
    return stock_price*pow(U,i)*pow(D,no_of_steps-i);
    
}
double EurOption::RiskNeutralProb(double U, double D, double interest)
{
        return ((interest)-D)/(U-D);
}
double EurOption::stock_movement_up(double stock_price, double U, int i,int no_of_steps)
{
    return stock_price*pow(U,no_of_steps-i);
}
double EurOption::stock_movement_down(double stock_price, double D, int no_of_steps, int i )
{
    return stock_price*pow(D,no_of_steps-i);
}
