//
//  EurOption.hpp
//  Eur_call
//
//  Created by Shankar on 10/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef EurOption_hpp
#define EurOption_hpp
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class EurOption
{
protected:
    double T_;
    double K_;
public:
    EurOption();
    EurOption(double T_,double K_);
    double N(double x);
    double d_plus(double S0, double sigma, double r);
    double d_minus(double S0, double sigma, double r);
    double VegaByBSFormula(double S0,double sigma, double r);
    virtual double PriceByBSFormula(double S0,double sigma,double r)=0;
    virtual double DeltaByBSFormula(double S0,double sigma,double r)=0;
    virtual double GammaByBSFormula(double S0,double sigma,double r)=0;
    virtual double payoff(double ST,double K)=0;
    double stock_movement(double,double,double,int,int);
    virtual double PriceByCRR(double,double,double,double,int,double)=0;
    virtual double PricebyTrinomial(double,double,int,double,double,double)=0;
    double RiskNeutralProb(double,double,double);
    double stock_movement_up(double,double,int,int);
    double stock_movement_down(double,double,int,int);

};


#endif /* EurOption_hpp */
