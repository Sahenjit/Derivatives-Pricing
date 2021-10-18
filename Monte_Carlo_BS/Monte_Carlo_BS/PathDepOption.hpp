//
//  PathDepOption.hpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef PathDepOption_hpp
#define PathDepOption_hpp
#include "BSModel.hpp"
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
    PathDepOption(double,int);
    virtual double PriceByMC(BSModel Model,long N,double)=0;
    virtual double PriceByMCRange(BSModel Model, long N,Stats1 s,double epsilon,Stats1 s1,Stats1 s2)=0;
    virtual double Payoff(SamplePath& S)=0;
    double getPricingError();
    void Rescale(SamplePath &S,double x);
    double getdelta();
    double getgamma();
};

#endif /* PathDepOption_hpp */
