//
//  main.cpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//
#include <iostream>
#include "BSModel101.hpp"
#include "Option.hpp"
#include "HeatEq.hpp"
#include "CNNMethod.hpp"
#include "BSLCP.hpp"
#include "ExplicitLCP.hpp"
int main()
{

double S0=100.0, r=0.05, sigma=0.25;
    BSModel Model(S0,r,sigma);
    double K=100.0, T=1., zl=0.0, zu=2.0*S0;
    Put PutOption(K,T,zl,zu);
   BSEqLCP BSLCP(&Model,&PutOption);
   int imax=5000, jmax=250;
   ExplicitLCP Method(&BSLCP, imax, jmax);
Method.SolveLCP();
cout << "Am Put Price = " << Method.v(0.0,S0) << endl;
Method.SolvePDE();
cout << "Eur Put Price = " << Method.v(0.0,S0) << endl;
return 0;
}
