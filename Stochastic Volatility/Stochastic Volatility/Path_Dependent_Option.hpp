//
//  Path_Dependent_Option.hpp
//  Stochastic Volatility
//
//  Created by Shankar on 31/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Path_Dependent_Option_hpp
#define Path_Dependent_Option_hpp
#include "BS_Model.hpp"
#include <cmath>
#include "Stats1.hpp"
class PathDepOption:public BSModel
{
protected:
    double T;
    int m;
    double Price;
    double PricingError;
    double delta;
    double gamma;
public:
    PathDepOption();
    PathDepOption(double,int);
    virtual double Payoff(SamplePath& S)=0;
    double getPricingError();
    void Rescale(SamplePath &S,double x);
    double getdelta();
    double getgamma();
};


#endif /* Path_Dependent_Option_hpp */
