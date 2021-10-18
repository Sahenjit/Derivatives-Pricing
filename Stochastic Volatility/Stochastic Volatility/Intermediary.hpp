//
//  Intermediary.hpp
//  Stochastic Volatility
//
//  Created by Shankar on 24/04/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Intermediary_hpp
#define Intermediary_hpp
#include "Function.hpp"
#include "European_Call.hpp"
class Eur_call;
class Intermediary:public Function
{
private:
    Eur_call *eur;
    double S0;
    double R;
public:
    Intermediary(double S,Eur_call *e,double r):eur(e),S0(S),R(r){};
    virtual double Value(double x) override;
    virtual double Deriv(double x) override;
};

#endif /* Intermediary_hpp */
