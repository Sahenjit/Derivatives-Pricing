//
//  American_Opt.cpp
//  Bino_Price
//
//  Created by Shankar on 02/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "American_Opt.hpp"
#include "Bino_Price.hpp"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
double American_option::PricebySnell(Bino_price Model)
{
    double q=Model.RiskNeutralProb();
    vector <double>Price(N+1);
    for (int i=0;i<=N;i++)
    {
        Price[i]=Payoff(Model.S(N,i));
    }
    for (int n=N-1;n>=0;n--)
    {
        for (int i=0;i<=N;i++)
        {
            double Contval=(q*Price[i+1]+(1-q)*Price[i])/(1+Model.getR());
            Price[i]=Payoff(Model.S(N,i));
            if(Contval>Price[i])
            {
                Price[i]=Contval;
            }
        }
    }
    return Price[0];
    
}
void American_option::SetN(int N_)
{
    N=N_;
}
