//
//  Range Accrual Note.cpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Range Accrual Note.hpp"

Range_Accrual::Range_Accrual(double T,double s_min,double s_max,double m,double M):PathDepOption(T, m)
{
    this->s_min=s_min;
    this->s_max=s_max;
    this->M=M;
    
}


double Range_Accrual::Payoff(SamplePath &s)
{
    int no_of_days=0;
    for (int i=0;i<s.size();i++)
        {
            if(s[i]>=s_min && s[i]<=s_max)
                no_of_days++;
        }
        
    return (M*no_of_days)/m;
}


double Range_Accrual::PriceByMCRange(BSModel Model, long N,Stats1 s,double epsilon,Stats1 s1,Stats1 s2)
{
    double H=0.0,Heps=0.0,Negative_heps=0;
    SamplePath S(m);
    for(long i=0;i<N;i++)
        {
            Model.GenerateSamplePath(T, m, S);
            H=Payoff(S);
            Rescale(S,1.0+epsilon);
            Heps=Payoff(S);
            Rescale(S,(1.0-epsilon-epsilon));
            Negative_heps=Payoff(S);
            s.add(H);
            s1.add(Heps);
            s2.add(Negative_heps);
            
        }
    double H_mean=s.mean();
    double H_stDev=s.stDev();
    double Heps_mean=s1.mean();
    double Negative_Heps_mean=s2.mean();
    Price= exp(-Model.getr()*T)*H_mean;
    PricingError=(exp(-Model.getr()*T)*H_stDev)/sqrt(N);
    delta=(exp(-Model.getr()*T)*(Heps_mean-H_mean))/(Model.getS0()*epsilon);
    gamma=((exp(-Model.getr()*T)*(Heps_mean))-(2*(exp(-Model.getr()*T)*(H_mean)))+(exp(-Model.getr()*T)*(Negative_Heps_mean)))/(pow(epsilon*Model.getS0(),2));
    return Price;
}

double Range_Accrual::PriceByMC(BSModel Model, long N, double epsilon)
    {
        double H=0.0, Hsq=0.0,Heps=0.0;
        SamplePath S(m);
        for(long i=0; i<N; i++)
        {
            Model.GenerateSamplePath(T,m,S);
            H = (i*H + Payoff(S))/(i+1.0);
            Hsq = (i*Hsq + pow(Payoff(S),2.0))/(i+1.0);
            Rescale(S,1.0+epsilon);
            Heps = (i*Heps + Payoff(S))/(i+1.0);
        }
        Price = exp(-Model.getr()*T)*H;
        PricingError = exp(-Model.getr()*T)*sqrt(Hsq-H*H)/sqrt(N-1.0);
        delta = exp(-Model.getr()*T)*(Heps-H)/(Model.getS0()*epsilon);
        return Price;
    }
