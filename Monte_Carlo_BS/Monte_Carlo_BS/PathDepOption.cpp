//
//  PathDepOption.cpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "PathDepOption.hpp"
#include "BSModel.hpp"
#include "Stats1.hpp"

void PathDepOption::Rescale(SamplePath &S, double x)
{
    double m=S.size();
    for(int j=0;j<m;j++)
        {
            S[j]=x*S[j];
        }
}


PathDepOption::PathDepOption(double T,int m):BSModel()
    {
        this->T=T;
        this->m=m;
    }

    
double PathDepOption::getPricingError()
    {
        return PricingError;
    }
double PathDepOption::getdelta()
    {
        return delta;
    }
double PathDepOption::getgamma()
    {
        return gamma;
    }

