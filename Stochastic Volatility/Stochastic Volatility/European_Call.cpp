//
//  European_Call.cpp
//  Stochastic Volatility
//
//  Created by Shankar on 01/04/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "European_Call.hpp"

template<typename Function>
double SolveByBisect(Function* Fct,double Tgt, double LEnd, double REnd, double Acc)
{
    double left=LEnd, right=REnd, mid=(left+right)/2;
    double y_left=Fct->Value(left)-Tgt, y_mid=Fct->Value(mid)-Tgt;
while (mid-left>Acc)
{
             if ((y_left>0 && y_mid>0)||(y_left<0 && y_mid<0))
                    {left=mid; y_left=y_mid;}
             else right=mid; mid=(left+right)/2; y_mid=Fct->Value(mid)-Tgt;
}
        return mid;
}


double N(double x)
{
    double gamma = 0.2316419;     double a1 = 0.319381530;
    double a2    =-0.356563782;   double a3 = 1.781477937;
    double a4    =-1.821255978;   double a5 = 1.330274429;
    double pi    = 4.0*atan(1.0); double k  = 1.0/(1.0+gamma*x);
    if (x>=0.0)
        {
            return 1.0-((((a5*k+a4)*k+a3)*k+a2)*k+a1)*k*exp(-x*x/2.0)/sqrt(2.0*pi);
        }
           else return 1.0-N(-x);
}

Eur_call::Eur_call():PathDepOption()
{
    K=0;
}

Eur_call::Eur_call(double K,double T,double m):PathDepOption(T,m)
{
    this->K=K;
}

double Eur_call::getK()
{
    return K;
}

double Eur_call::PricebyMC(BSModel Model, long N)
{
    double H=0.0;
    double v1=0.0;
    SamplePath s(m);
    Volatility v(m);
    for(long i=0;i<N;i++)
        {
            Model.EulerScheme(v,T,m);
            Model.GenerateSamplePath(T, m, s, v);
            H=Payoff(s);
            s1.add(H);
            s2.add(v1);
            
        }
    double H_mean=s1.mean();
    return exp(-Model.getr()*T)*H_mean;
}

double Eur_call::Payoff(SamplePath &S)
{
    double payoff=0;
   
            if(S[S.size()-1]>K)
                {
                    payoff=payoff+(S[S.size()-1]-K);
                }
    return (payoff);
}

double Eur_call::d_plus(double S0,double sigma,double r)
{
        return (log(S0/K)+ (r+0.5*pow(sigma,2.0))*T) /(sigma*sqrt(T));
}

double Eur_call::d_minus(double S0,double sigma,double r)
{
        return d_plus(S0,sigma,r)-sigma*sqrt(T);
}

double Eur_call::PriceByBSFormula(double S0,double sigma,double r)
{
        return S0*N(d_plus(S0,sigma,r))-K*exp(-r*T)*N(d_minus(S0,sigma,r));
}
double Eur_call::Implied_vol(double Price,double S0, double r)
{
    Intermediary im(S0, this, r);
    
    return SolveByBisect(&im, Price, -1, 20000, 0.0001);
}
