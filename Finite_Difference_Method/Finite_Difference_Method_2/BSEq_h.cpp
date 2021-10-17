//
//  BSEq_h.cpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "BSEq_h.hpp"
#include <cmath>
BSEq::BSEq(BSModel* PtrModel_,Option* PtrOption_)
{
   PtrModel=PtrModel_; PtrOption=PtrOption_;
   T =PtrOption->T;
   xl=PtrOption->zl;
   xu=PtrOption->zu;
}

double BSEq::a(double t, double z)
{
   return -0.5*pow(PtrModel->sigma*z,2.0);
}

double BSEq::b(double t, double z)
{
   return -PtrModel->r*z;
}

double BSEq::c(double t, double z)
{
   return PtrModel->r;
}

double BSEq::d(double t, double z)
{
   return 0.0;
}

double BSEq::f(double z)
{
   return PtrOption->Payoff(z);
}

double BSEq::fl(double t)
{
   return PtrOption->LowerBdCond(PtrModel,t);
}

double BSEq::fu(double t)
{
   return PtrOption->UpperBdCond(PtrModel,t);
}
