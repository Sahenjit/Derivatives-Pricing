//
//  DiscountCurve.cpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "DiscountCurve.hpp"

Discount_Factor_Curve::Discount_Factor_Curve()
{
    m_interpolator.insert(0, 1);
}

void Discount_Factor_Curve::insert(double T, double D)
{
    m_interpolator.insert(T, D);
}

double Discount_Factor_Curve::discount_factor(double T)
{
   return m_interpolator.value(T);
}
