//
//  Eur_call.cpp
//  Trapozodial
//
//  Created by Shankar on 15/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Eur_call.hpp"


Eurcall::Eurcall()
{
    a=0;
    strike_price=0;
}


Eurcall::Eurcall(double a,double strike_price)
{
    this->a=a;
    this->strike_price=strike_price;
}


double Eurcall::payoff_call(double a)
{
    
    if (a>strike_price)
    {
        double payoff=a-strike_price;
        return payoff;
    }
    else
    {
        return 0;
    }
}

