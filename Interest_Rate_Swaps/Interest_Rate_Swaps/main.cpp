//
//  main.cpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include "Swaps.hpp"
#include "Bootstrapper.hpp"
#include "DiscountCurve.hpp"
int main()
{
    int freq=2;
    std::vector<Swap> swaps;
    swaps.push_back(Swap(1, freq, (2.64/100)));
    swaps.push_back(Swap(2, freq, (3.02/100)));
    swaps.push_back(Swap(3, freq, (3.42/100)));
    swaps.push_back(Swap(5, freq, (4.11/100)));
    swaps.push_back(Swap(7, freq, (4.56/100)));
    swaps.push_back(Swap(10,freq, (4.97/100)));
    
    Bootstrapper b(swaps);
    b.calculate(Discount_Factor_Curve &d);
}
