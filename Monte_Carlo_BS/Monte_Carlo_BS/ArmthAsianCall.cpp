//
//  ArmthAsianCall.cpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "ArmthAsianCall.hpp"


ArmthAsianCall::ArmthAsianCall(double T,double K,int m):PathDepOption(T, m)
    {
        this->K=K;
    }



double ArmthAsianCall::Payoff(SamplePath &S)
{
    double Ave=0.0;
    for(int k=0;k<m;k++)
    {
        Ave=(k*Ave+S[k])/(k+1.0);
    }
        if(Ave<K)
            return 0.0;
     
        return Ave-K;
        
}

double ArmthAsianCall::PriceByMC(BSModel Model, long N, double epsilon)
{
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
}
double ArmthAsianCall::PriceByMCRange(BSModel Model, long N,Stats1 s,double epsilon,Stats1 s1,Stats1 s2)
    {
        return 0;
    }
