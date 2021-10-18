//
//  Intermediary.cpp
//  Stochastic Volatility
//
//  Created by Shankar on 24/04/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Intermediary.hpp"

double Intermediary::Value(double x)
{
    return eur->PriceByBSFormula(S0, x, R);
}

double Intermediary::Deriv(double x)
{
    return 0;
}
