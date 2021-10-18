//
//  main.cpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include "BSModel.hpp"
#include "PathDepOption.hpp"
#include "ArmthAsianCall.hpp"
#include "Range Accrual Note.hpp"
#include "Stats1.hpp"
int main()
{
    int selection;
    cout<<"Please enter if you would like a asian option or range accrual: ";
    cin>>selection;
    if(selection==1)
    {
        double S0=100.0, r=0.03, sigma=0.2,epsilon=0.001;
        BSModel Model(S0,r,sigma);
        double T=1.0/12.0, K=100.0; int m=30;
        ArmthAsianCall Option(T,K,m);
        long N=30000;
        for (int i=0;i<100;i++)
            {
                cout << "Asian Call Price = "<< Option.PriceByMC(Model,N,epsilon) << endl;
                cout<<"Pricing Error: "<<Option.getPricingError()<<endl;
                cout<<"The delta is: "<<Option.getdelta()<<endl;
            }
    }
    else if(selection==2)
    {
        double S0=105.0, r=0.05, sigma=0.25,s_min=100,s_max=110, M=1000000,d=252,epsilon=0.001;
         BSModel Model(S0,r,sigma);
         Stats1 s;
         Stats1 s1;
         Stats1 s2;
         double T=1.0;
        Range_Accrual Option(T, s_min, s_max,d,M);
        long N=300000;
         
             cout<<"The Range accrual note is: "<<Option.PriceByMCRange(Model,N,s,epsilon,s1,s2)<<endl;
             cout<<"The Standard error is: "<<Option.getPricingError()<<endl;
             cout<<"The delta for the range accrual is: "<<Option.getdelta()<<endl;
             cout<<"The gamma for the range accrual is; "<<Option.getgamma()<<endl;
             cout<<endl;
        
    }
    return 0;
}



