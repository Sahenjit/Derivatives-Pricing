//
//  Eurput.cpp
//  Trapozodial
//
//  Created by Shankar on 15/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Eurput.hpp"



Eurput::Eurput()
{
    a=0;
    strike_price=0;
}
Eurput::Eurput(double a,double strike_price)
{
    this->a=a;
    this->strike_price=strike_price;
}

double Eurput::payoff_put(double a)
{
  
        if(strike_price>a)
        {
            double payoff=strike_price-a;
            return payoff;
        }
        else
        {
            return 0;
        }
        
}
