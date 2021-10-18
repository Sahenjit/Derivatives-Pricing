//
//  ArmthAsianCall.hpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef ArmthAsianCall_hpp
#define ArmthAsianCall_hpp
#include "BSModel.hpp"
#include "PathDepOption.hpp"
#include "Stats1.hpp"
class ArmthAsianCall:public PathDepOption
{
private:
    double K;
public:
    ArmthAsianCall(double ,double ,int);
    virtual double Payoff(SamplePath &) override;
    virtual double PriceByMC(BSModel Model,long N,double) override;
    virtual double PriceByMCRange(BSModel Model, long N,Stats1 s,double epsilon,Stats1 s1,Stats1 s2) override;
};

#endif /* ArmthAsianCall_hpp */
