//
//  Swaps.hpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Swaps_hpp
#define Swaps_hpp
#include "DiscountCurve.hpp"
class Swap
{
private:
    int maturity;
    double swap_rate;
    int no_of_cash_flow_payments;
public:
    Swap(int maturity,double swap_rate,int no_of_cash_flow_payments);
    double fixed_leg(Discount_Factor_Curve &dc);
    double float_leg(Discount_Factor_Curve &dc);
    double present_value(Discount_Factor_Curve &dc);
    int getmaturity();
    double getswap_rate();
    int getno_of_cash_flow_payments();
};

#endif /* Swaps_hpp */
