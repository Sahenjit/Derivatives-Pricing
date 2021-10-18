//
//  Eur_call_MC.cpp
//  Jump_Diffusion
//
//  Created by Shankar on 06/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Eur_call_MC.hpp"
#include <cmath>
#include <random>
#include <iostream>
#include <stdlib.h>

double U1()
{
    const double u1 = static_cast<double>(rand()) / (RAND_MAX);
    return u1;
}
double U2()
{
    const double u2 = static_cast<double>(rand()) / (RAND_MAX);
    return u2;
}

double Z1()
{
    const double TWO_PI = 6.2831853071795862;
    double z1=sqrt(-2*log(U1()))*cos(TWO_PI*U2());
    return z1;
}

double Z2()
{
    const double TWO_PI = 6.2831853071795862;
    double z2=sqrt(-2*log(U1()))*sin(TWO_PI*U2());
    return z2;
}

Eur_call_MC::Eur_call_MC()
{
    
}

Eur_call_MC::Eur_call_MC(double T_,double K_,double S0)
{
    this->T_=T_;
    this->K_=K_;
    this->S0=S0;
}

void Eur_call_MC::GenerateSamplePath(double T, int n_steps, SamplePath &S,double risk_neut_drift,double sigma,double s,double prob_jump,double m)
{
    double St=S0;
       for(int k=0;k<n_steps;k++)
           {
               S[k]=St*exp((risk_neut_drift*T/n_steps)+(sigma*sqrt(T/n_steps))*Z1());
               double u = static_cast<double>(rand() + 0.5) / (RAND_MAX+1.0);
               if (u <= prob_jump)// How to check if a jump happens. In order to find if a jump occurs we selected a Random number uniformly from [0,1] if this number is less than then the fixed probability of jump(prob_jump=lambda*dt) then the probability that u is less than p happens with probability p and a jump ocurrs.
                {
                    S[k] =S[k]*exp(m + s * Z2()); //In this step the stock price of S will jump from S to J*S as the share price has jumped. J is log-normally distrbuted. If a standard normal variable Z is chosen with mean 0 and standard deviation 1 then a Z=(X - mu) / sigma. Re-arranging we get X= z*sigma + mu. J is said to be log normally distrubuted  when Y=ln(J) re arranging this we get exp(Y)=J. If Y=z*sigma + mu then J=exp(m+s*Z2()). Hence we get S[k] *log(m+s*Z2()) where S[K] is evolution of the stock price and J=exp(m+s*Z2()).
                }
               St=S[k];
           }
}

double Eur_call_MC::payoff(SamplePath &S)
{
    double payoff=0;
    
             if(S[S.size()-1]>K_)
                 {
                     payoff=payoff+(S[S.size()-1]-K_);
                 }
     return (payoff);
}

double Eur_call_MC::PricebyMc(double dt,double s,double m,double lambda,double sigma,double r,double n_steps)
{
    Stats1 s1;
    double Price;
    double no_of_sims=760000;
    double prob_jump=lambda*(dt);
    SamplePath S(n_steps);
    double k=exp(m+pow(s,2)/2)-1;
    double risk_neut_drift=(r-(pow(sigma,2)/2))-(lambda*k);
    
    for(int i=0;i<no_of_sims;i++)
    {
        this->GenerateSamplePath(T_,n_steps,S,risk_neut_drift,sigma,s,prob_jump,m);
        double payoff=this->payoff(S);
        s1.add(payoff);
    }
    return Price=s1.mean()*exp(-r*T_);
}
