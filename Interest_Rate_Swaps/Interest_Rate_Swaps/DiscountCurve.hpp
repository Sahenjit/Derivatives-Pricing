//
//  DiscountCurve.hpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef DiscountCurve_hpp
#define DiscountCurve_hpp
#include "interpolator.h"
class Discount_Factor_Curve
{
private:
    LinearInterpolator m_interpolator;
public:
    Discount_Factor_Curve();
    void insert(double T, double D);
    double discount_factor(double T);
};

#endif /* DiscountCurve_hpp */
