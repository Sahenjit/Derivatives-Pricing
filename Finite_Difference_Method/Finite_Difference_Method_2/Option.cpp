//
//  Option.cpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Option.hpp"
#include <cmath>

double Put::Payoff(double z)
{
   if (K<z) return 0.0;
   return K-z;
}

double Put::UpperBdCond(BSModel* PtrModel, double t)
{
   return 0.0;
}

double Put::LowerBdCond(BSModel* PtrModel, double t)
{
   return K*exp(-PtrModel->r*(T-t));
}
