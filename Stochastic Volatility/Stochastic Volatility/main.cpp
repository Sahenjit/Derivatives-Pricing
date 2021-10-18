//
//  main.cpp
//  Stochastic Volatility
//
//  Created by Shankar on 31/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <random>
#include "BS_Model.hpp"
#include "Path_Dependent_Option.hpp"
#include "European_Call.hpp"


int main()
{
   
    int S0=100;
    double r=0.05;
    double V0=pow(0.2,2);
    double v_mean=pow(0.3,2);
    double a=1.25;
    double eta=0.3;
    double correlation=0.1;
    double m=366;
    double T=1.0;
    long N=330000;
    BSModel h(S0,r,a,eta,v_mean,V0,correlation);
    for (int i=60;i<=150;i++)
    {
        Eur_call c(i,T,m);
        double Price=c.PricebyMC(h, N);
        cout<<c.Implied_vol(Price, S0,r)<<endl;
        //cout<<"This implied volatility is: "<<c.Implied_vol(Price, S0,r)<<endl;
    }
    
   
}
