//
//  main.cpp
//  Trapozodial
//
//  Created by Shankar on 11/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

    #include <iostream>
    #include "Trap.hpp"
    #include "Eur_call.hpp"
    #include "Eurput.hpp"
    using namespace std;
    int main()
    {
        
        double a=0.01;
        double b=1000;
        double r=0.06;
        double t=0.75;
        double k=102;
        double sigma=0.25;
        double S0=100;
        
        Eurcall(a,k);
        Eurput(a,k);
        DefInt d(a,b,r,t,k);
        cout<<d.calc_mean(S0,r,t,sigma)<<endl;
        cout<<d.calc_st_Dev(sigma, t)<<endl;
        cout<<d.lognormal(a,b)<<endl;
       
        
        
        
    }
