//
//  Bootstrapper.cpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Bootstrapper.hpp"




Bootstrapper::Bootstrapper(std::vector<Swap> swaps)
{
    this->swaps=swaps;
}

void Bootstrapper::calculate(Discount_Factor_Curve &d)
{
    for (vector<Swap>::iterator it= swaps.begin();it!=swaps.end();it++)
    {
        
        
        
        double discount_factor=SolveByBisect(<#Function *Fct#>, 0, 0, 1, 0.0000001);
        d.insert(it->getmaturity(), discount_factor);
        
    }
}
