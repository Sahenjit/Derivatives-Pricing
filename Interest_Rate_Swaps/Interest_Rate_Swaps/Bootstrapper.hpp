//
//  Bootstrapper.hpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Bootstrapper_hpp
#define Bootstrapper_hpp
#include "DiscountCurve.hpp"
#include "Swaps.hpp"
#include <vector>
#include "Solver_02.hpp"
class Bootstrapper
{
private:
    std::vector<Swap> swaps;
public:
    Bootstrapper(std::vector<Swap> swaps);
    void calculate(Discount_Factor_Curve &d);
};

#endif /* Bootstrapper_hpp */
