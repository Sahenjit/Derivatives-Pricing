//
//  Trap.hpp
//  Trapozodial
//
//  Created by Shankar on 11/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Trap_hpp
#define Trap_hpp

#include <iostream>
#include <cmath>
#include "Eur_call.hpp"
#include "Eurput.hpp"
using namespace std;
class DefInt:public Eurcall,public Eurput
{
private:
    double a;
    double b;
    double N;
    double mean;
    double st_Dev;
    double h;
    double interest;
    double t;
    double strike_price;
public:
    DefInt();
    DefInt (double a,double b,double,double,double);
    double calc_mean(double,double,double,double);
    double calc_st_Dev(double,double);
    double Eur_payoff_call(double);
    double Eur_payoff_put(double);
    double lognormal(double,double);
};

#endif /* Trap_hpp */
