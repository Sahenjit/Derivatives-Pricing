//
//  Swaps.cpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Swaps.hpp"

Swap::Swap(int maturity,double swap_rate,int no_of_cash_flow_payments) //note look up member initilisation
{
    this->maturity=maturity;
    this->swap_rate=swap_rate;
    this->no_of_cash_flow_payments=no_of_cash_flow_payments;
}

double Swap::fixed_leg(Discount_Factor_Curve &dc)
{
    double price=0;
    double discount_val=0;
    int total_payments=no_of_cash_flow_payments*maturity;
    for (int i=1;i<total_payments;i++)
    {
        discount_val=discount_val+dc.discount_factor((static_cast<double> (i)/no_of_cash_flow_payments));
    }
    price=(swap_rate/no_of_cash_flow_payments)*discount_val;
    return price;
}

double Swap::float_leg(Discount_Factor_Curve &dc)
{
    return 1-dc.discount_factor(maturity);
}

double Swap::present_value(Discount_Factor_Curve &dc)
{
    double present_val=fixed_leg(dc)-float_leg(dc);
    return present_val;
}

int Swap::getmaturity()
{
    return maturity;
}
