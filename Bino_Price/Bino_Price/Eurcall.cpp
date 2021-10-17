//
//  Eurcall.cpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Eurcall.hpp"

#include <iostream>
using namespace std;

int Eurcall::GetInputData()
{
    cout<<"Enter call option data: "<<endl;
    int N;
    cout<<"Enter the steps to expiry N";
    cin>>N;
    Euroption::SetN(N);American_option::SetN(N);
    cout<<"Enter the strike price: ";
    cin>>K;
    cout<<endl;
    return 0;
}
double Eurcall::Payoff(double z)
{
    if (z>K)
    {
    return z-K;
    }
    else
    {
        return 0;
    }
}
void Eurcall::SetK(double K_)
{
    K=K_;
}

