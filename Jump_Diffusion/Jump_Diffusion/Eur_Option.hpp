//
//  Eur_Option.hpp
//  Jump_Diffusion
//
//  Created by Shankar on 05/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Eur_Option_hpp
#define Eur_Option_hpp
#include <vector>
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
    virtual double PriceByBSFormula(double S0,double sigma,double r)=0;
};

#endif /* Eur_Option_hpp */
