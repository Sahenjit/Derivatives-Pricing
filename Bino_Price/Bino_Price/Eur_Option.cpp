//
//  Eur_Option.cpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//
#include "Bino_Price.hpp"
#include "Eur_Option.hpp"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

double Euroption::PricebyCRR(Bino_price Model)
{
    double q=Model.RiskNeutralProb();
    vector<double>Price(N+1);
    for (int i=0; i<=N;i++)
    {
        Price[i]=Payoff(Model.S(N,i));
    }
    for (int i=N;N>0;i--)
    {
        for (int i=0;i<N-1;i++)
        {
            Price[i]=(q*Price[i+1]+(1-q)*Price[i])/(1+Model.getR());
        }
    }
    return Price[0];
}
void Euroption::SetN(int N_)
{
    N=N_;
}

