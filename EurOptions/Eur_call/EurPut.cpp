//
//  EurPut.cpp
//  Eur_call
//
//  Created by Shankar on 10/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "EurPut.hpp"
#include "EurOption.hpp"
#include <cmath>
#include <iostream>

using namespace std;

EurPut::EurPut(double T_,double K_):EurOption(T_, K_)
{
}
double EurPut::PriceByBSFormula(double S0,double sigma,double r)
{
    return
    -1*S0*EurOption::N(-d_plus(S0,sigma,r))+K_*exp(-r*T_)*EurOption::N(-d_minus(S0,sigma,r));
}
double EurPut::DeltaByBSFormula(double S0,double sigma,double r)
{
    return 1-EurOption::N(d_plus(S0,sigma,r));
}
double EurPut::GammaByBSFormula(double S0,double sigma,double r)
{
    double x=(1/S0*sigma*sqrt(T_));
    double y=(1/sqrt(2*3.141592));
    double z=exp(EurOption::N(-d_plus(S0,sigma,r)));
    return x*y*z;
}
double EurPut::payoff(double ST, double K)
{
    if(K>ST)
    {
        return K-ST;
    }
    return 0;
}

double EurPut::PriceByCRR(double stock_price, double U, double D, double interest, int no_of_steps, double K)
{
    {
        if(stock_price<=0 || U<=-1.0 ||D<=-1.0 ||U<=D ||interest<=-1.0)
        {
            cout<<"Illegal data ranges"<<endl;
            cout<<"Terminating program"<<endl;
            return 1;
        }
        if(interest>=U || interest<=D)
        {
            cout<<"Arbitage exists"<<endl;
            cout<<"Terminating program"<<endl;
            return 1;
        }
        vector<double>Price(2*(no_of_steps)+1);
       
        for (int i=0;i<=2;i++)
        {
            
            
            Price[i]=payoff(EurOption::stock_movement(stock_price,U,D,no_of_steps,i),K);
           
        
        }
        for (int n=no_of_steps;n>0;n--)
                 
        {
            for (int i=0;i<=no_of_steps-1;i++)
            {
                Price[i]=(EurOption::RiskNeutralProb(U,D,interest)*Price[i+1]+(1-EurOption::RiskNeutralProb(U,D,interest))*Price[i])/(interest);
              
             
            }
        }
        return (Price[0])/2;
    }
}

double EurPut::PricebyTrinomial(double stock_price, double interest, int no_of_steps, double K,double time_step,double sigma)
{
    return 0;
}

