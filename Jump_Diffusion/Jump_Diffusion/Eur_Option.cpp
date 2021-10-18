//
//  Eur_Option.cpp
//  Jump_Diffusion
//
//  Created by Shankar on 05/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Eur_Option.hpp"
#include <iostream>
#include <cmath>

using namespace std;

EurOption::EurOption()
{
    T_=0;
    K_=0;
}
EurOption::EurOption(double T_,double K_)
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

