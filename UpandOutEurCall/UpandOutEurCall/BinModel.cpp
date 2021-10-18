//
//  BinModel.cpp
//  UpandOutEurCall
//
//  Created by Shankar on 21/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "BinModel.hpp"
#include <iostream>
#include <cmath>
using namespace std;

double BinModel::RiskNeutProb(double U,double D,double interest)
{
    return ((interest)-D)/(U-D);
}
double BinModel::S(double stock_price,double U,double D,int no_of_steps,int i)
{
    return stock_price*pow(U,i)*pow(D,no_of_steps-i);
}
