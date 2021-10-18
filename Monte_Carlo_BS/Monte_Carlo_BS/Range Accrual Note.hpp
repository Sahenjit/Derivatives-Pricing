//
//  Range Accrual Note.hpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Range_Accrual_Note_hpp
#define Range_Accrual_Note_hpp
#include "PathDepOption.hpp"
#include <cmath>
class Range_Accrual:public PathDepOption
{
private:
    double K;
    double s_min;
    double s_max;
    double M;
public:
    Range_Accrual(double,double,double,double,double);
    virtual double Payoff(SamplePath &s) override;
    virtual double PriceByMCRange(BSModel Model, long N,Stats1 s,double epsilon,Stats1 s1,Stats1 s2) override;
    virtual double PriceByMC(BSModel Model,long N,double) override;
};

#endif /* Range_Accrual_Note_hpp */
