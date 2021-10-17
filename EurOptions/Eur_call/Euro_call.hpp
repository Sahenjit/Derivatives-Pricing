//
//  Euro_call.hpp
//  Eur_call
//
//  Created by Shankar on 10/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Euro_call_hpp
#define Euro_call_hpp

#include "EurOption.hpp"

class EurCall:public EurOption
{
public:
    EurCall(double T_, double K_);
    virtual double PriceByBSFormula(double S0,double sigma, double r) override;
    virtual double DeltaByBSFormula(double S0,double sigma,double r) override;
    virtual double GammaByBSFormula(double S0,double sigma,double r) override;
    virtual double payoff(double ST,double K) override;
    virtual double PriceByCRR(double,double,double,double,int,double) override;
    virtual double PricebyTrinomial(double,double,int,double,double,double) override;
    
};




#endif /* Euro_call_hpp */
