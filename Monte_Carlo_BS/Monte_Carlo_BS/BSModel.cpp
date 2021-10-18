//
//  BSModel.cpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "BSModel.hpp"
#include <cmath>
const double pi=4.0*atan(1.0);

BSModel::BSModel()
    {
        S0=0;
        r=0;
        sigma=0;
    }
BSModel::BSModel(double S0,double r,double sigma)
    {
        this->S0=S0;
        this->r=r;
        this->sigma=sigma;
        srand(time(NULL));
    }
double Guass()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}
void BSModel::GenerateSamplePath(double T, int m, SamplePath &S)
{
    double St=S0;
    for(int k=0;k<m;k++)
        {
            S[k]=St*exp((r-sigma*sigma*0.5)*(T/m) +sigma*sqrt(T/m)*Guass());
            St=S[k];
        }
}
double BSModel::getr()
{
    return r;
}
double BSModel::getS0()
{
    return S0;
}
double BSModel::getsigma()
{
    return sigma;
}
