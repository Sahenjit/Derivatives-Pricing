//
//  Jump_Diffusion.hpp
//  Jump_Diffusion
//
//  Created by Shankar on 05/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Jump_Diffusion_hpp
#define Jump_Diffusion_hpp
#include "Eur_Option.hpp"
#include <vector>
#include "Intermediary.hpp"
class Eur_call_analytic:public EurOption
{
public:
    Eur_call_analytic();
    Eur_call_analytic(double T_,double K_);
    virtual double PriceByBSFormula(double S0,double sigma,double r) override;
    double factorial(int);
    double Implied_vol(double Price,double S0,double r);
    double Jump_Diffusion(double,double,double,double,double,double);
  
    
};

#endif /* Jump_Diffusion_hpp */
