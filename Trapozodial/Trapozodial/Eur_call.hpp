//
//  Eur_call.hpp
//  Trapozodial
//
//  Created by Shankar on 15/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Eur_call_hpp
#define Eur_call_hpp

#include <iostream>
#include <cmath>

using namespace std;
class Eurcall
{
protected:
    double a;
    double strike_price;
public:
    Eurcall();
    Eurcall(double,double);
    double payoff_call(double);
};

#endif /* Eur_call_hpp */
