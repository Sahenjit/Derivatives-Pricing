//
//  European_Call.hpp
//  Stochastic Volatility
//
//  Created by Shankar on 01/04/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef European_Call_hpp
#define European_Call_hpp
#include "BS_Model.hpp"
#include "Path_Dependent_Option.hpp"
#include "Stats1.hpp"
#include <cmath>
#include "Intermediary.hpp"
class Eur_call:public PathDepOption
{
private:
    double K;
    Stats1 s1;
    Stats1 s2;
public:
    Eur_call();
    Eur_call(double,double,double);
    double getK();
    double PricebyMC(BSModel Model,long N);
    double d_plus(double S0,double sigma,double r);
    double d_minus(double S0,double sigma,double r);
    double PriceByBSFormula(double S0,double sigma, double r);
    virtual double Payoff(SamplePath& S) override;
    double Implied_vol(double Price,double S0,double r);
};


#endif /* European_Call_hpp */
