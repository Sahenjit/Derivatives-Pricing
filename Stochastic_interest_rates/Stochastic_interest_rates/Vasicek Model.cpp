//
//  Vasicek Model.cpp
//  Stochastic_interest_rates
//
//  Created by Shankar on 15/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Vasicek Model.hpp"
#include <cmath>
#include <iostream>

Vasicek_Model::Vasicek_Model(double a,double b, double sigma, double r0,double T)
{
    this->a=a;
    this->b=b;
    this->sigma=sigma;
    this->r0=r0;
    this->T=T;
}

double Vasicek_Model::GenerateSamplePath(double m,SamplePath &r)
{
    NormalRandomGenerator n;
    double time_step=T/m;
    double rt=r0;
    double interest_rate_values=0;
    r.insert(r.begin(), r0);
    for (int k=0;k<m-1;k++)
    {
        double Z1=n.generate_z1();
        r[k+1]=(a*(b-rt)*(time_step)+sigma*sqrt(time_step)*Z1)+r[k];
        rt=r[k+1];
        interest_rate_values=(interest_rate_values+(r[k+1]));
    }
    return interest_rate_values*time_step;
}

double Vasicek_Model::Payoff(SamplePath &r, double M, double K)
{
    if(r.end()[-2]>K)
    {
        return M*(r.end()[-2]-K);
    }
    else
        return 0;
}


double Vasicek_Model::PriceByMc(double m)
{
    double no_of_sims=7300;
    Stats1 s;
    for (int i=0;i<no_of_sims;i++)
    {
        SamplePath r(m);
        double interest_rate_values=this->GenerateSamplePath(m,r);
        double Path_dep_DF=exp(-interest_rate_values);
        s.add(Path_dep_DF);
    }
    return s.mean();
}
double Vasicek_Model::Price_By_Mc_2(double m, double K, double M)
{
    double no_of_sims=55000;
    Stats1 s;
    Stats1 s1;
    for (int i=0;i<no_of_sims;i++)
    {
        SamplePath r(m);
        double interest_rate_values=this->GenerateSamplePath(m, r);
        double Path_dep_DF=exp(-interest_rate_values);
        double Payoff=this->Payoff(r, M, K);
        s.add(Payoff*Path_dep_DF);
    }
    cout<<s.mean()<<endl;
    double Price=s.mean();
    return Price;
}


void Vasicek_Model::Interest_rate_hist(double m,double x_min)
{
    SamplePath r(m);
    Histogram h(x_min,T,m);
    vector<double> a1;
    vector<unsigned int> b1;
    this->GenerateSamplePath(m,r);
    for (int i=0;i<r.size();i++)
        {
            h.add(r[i]);
        }
        h.getResults(a1, b1);
        h.writetostream(a1, b1);
}

