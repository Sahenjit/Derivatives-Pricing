//
//  BS_Model.cpp
//  Stochastic Volatility
//
//  Created by Shankar on 31/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "BS_Model.hpp"
#include <cmath>
#include <numeric>
const double pi=4.0*atan(1.0);

BSModel::BSModel()
    {
        S0=0;
        r=0;
    }
BSModel::BSModel(double S0,double r,double a,double eta,double v_mean,double V0,double correlation)
    {
        this->S0=S0;
        this->r=r;
        this->a=a;
        this->eta=eta;
        this->v_mean=v_mean;
        this->V0=V0;
        this->correlation=correlation;
        srand(time(NULL));
    }
double E1()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * cos(2.0*pi*U2);
}
double Guass_num_2()
{
    double U1 = (rand()+1.0)/(RAND_MAX+1.0);
    double U2 = (rand()+1.0)/(RAND_MAX+1.0);
    return sqrt(-2.0*log(U1)) * sin(2.0*pi*U2);
}
double BSModel::Z1()
{
    double z1=E1();
    return z1;
}

double BSModel::E2()
{
    double z2=Guass_num_2();
    return z2;
}

double BSModel::Z2(double correlation)
{
    double z2=(correlation*E1())+(sqrt(1-pow(correlation,2))*E2());
    return z2;
}
void BSModel::EulerScheme(Volatility &v,double T,double m)
{
    {
        double V=V0;
        double time_step=T/m;
        for (int k=0;k<m;k++)
            {
                v[k]=pow(sqrt(V)+((eta/2)*sqrt(time_step)*BSModel::Z2(correlation)),2)-(a*(time_step*(V-v_mean)))-(time_step*(pow(eta,2)/4));
                V=v[k];
            }
    }
}


void BSModel::GenerateSamplePath(double T, int m, SamplePath &S,Volatility &v)
{
    double St=S0*exp((r-V0*0.5)*(T/m)+sqrt(V0*(T/m))*Z1());
    for(int k=0;k<m;k++)
        {
            S[k]=St*exp((r-(v[k]/2))*(T/m)+sqrt(v[k]*(T/m))*Z1());;
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
