//
//  Intermediary.hpp
//  Jump_Diffusion
//
//  Created by Shankar on 06/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Intermediary_hpp
#define Intermediary_hpp
#include "Function.hpp"
#include "Eur_call_analytic.hpp"
class Eur_call_analytic;
class Intermediary:public Function
{
private:
    Eur_call_analytic *eur;
    double S0;
    double R;
public:
    Intermediary(double S,Eur_call_analytic *e,double r):eur(e),S0(S),R(r){};
    virtual double Value(double x) override;
    virtual double Deriv(double x) override;
};

#endif /* Intermediary_hpp */
