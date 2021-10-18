//
//  main.cpp
//  Stochastic_interest_rates
//
//  Created by Shankar on 15/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include "Histogram.hpp"
#include "NormalRandomGenerator.hpp"
#include "Vasicek Model.hpp"
using namespace std;

int main()
{
    double a=0.25;
    double b=0.1;
    double sigma=0.02;
    double r0=0.07;
    double T=5;
    double x_min=0;
    double m=50000;
    double K=0.11;
    double M=1000000;
    Vasicek_Model v(a,b,sigma,r0,T);
    cout<<v.PriceByMc(m)<<endl;
    cout<<v.Price_By_Mc_2(m, K, M)<<endl;
}
