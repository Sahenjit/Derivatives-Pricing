//
//  main.cpp
//  Jump_Diffusion
//
//  Created by Shankar on 05/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include "Eur_call_analytic.hpp"
#include "Eur_call_MC.hpp"
using namespace std;
int main()
{
    double S0=100;
    double r=0.05;
    double T=0.5;
    double sigma=0.15;
    double lambda=1;
    double m=0.05;
    double s=0.3;
    double K=105;
    double n_steps=52;
    double dt=T/n_steps;
    for (int i=60;i<150;i++)
    {
        Eur_call_analytic c(T,i);
        double Price=c.Jump_Diffusion(S0, r, sigma, lambda, m, s);
        cout<<"The price of the call option is the following: "<<Price<<endl;
        cout<<"The implied Volatility is: "<<c.Implied_vol(Price, S0, r)<<endl;
    }
    
       Eur_call_MC mc(T,K,S0);
       cout<<mc.PricebyMc(dt,s, m, lambda, sigma, r, n_steps);
}
    
