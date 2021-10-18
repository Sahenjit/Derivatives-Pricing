//
//  Jump_Diffusion.cpp
//  Jump_Diffusion
//
//  Created by Shankar on 05/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Eur_call_analytic.hpp"
#include <cmath>
#include <random>
using namespace std;


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

Eur_call_analytic::Eur_call_analytic():EurOption()
{
}

Eur_call_analytic::Eur_call_analytic(double T_,double K_):EurOption(T_,K_)
{
    
}

double Eur_call_analytic::PriceByBSFormula(double S0,double sigma, double r)
{

   return S0*EurOption::N(d_plus(S0,sigma,r))-K_*exp(-r*T_)*EurOption::N(d_minus(S0,sigma,r));
}

double Eur_call_analytic::factorial(int i)
{
    double fact=1;
    for (int k=i;k>0;k--)
        {
            fact=fact*k;
        }
    return fact;
}

double Eur_call_analytic:: Jump_Diffusion(double S0,double r,double sigma,double lambda,double m,double s)
{
    Eur_call_analytic c(T_,K_);
    double k=exp(m+pow(s,2)/2)-1;
    double sigma_iter;
    double interest_iter;
    double lambda_bar=lambda*(1+k);
    double sum=0;
    for (int i=0;i<20;i++)
        {
            sigma_iter=sqrt(pow(sigma,2)+(i*pow(s, 2))/T_);
            interest_iter=(r)-(lambda*k)+((i*log(1+k))/T_);
            sum=sum+((((exp(-lambda_bar*T_))*pow(lambda_bar*T_,i))/c.factorial(i))*(c.PriceByBSFormula(S0, sigma_iter, interest_iter)));
        }
    return sum;
}

double Eur_call_analytic::Implied_vol(double Price,double S0, double r)
{
    Intermediary im(S0, this, r);
    
    return SolveByBisect(&im, Price, -1, 20000, 0.0001);
}
