//
//  Gilt.hpp
//  Gilt
//
//  Created by Shanka on 04/03/2020.
//  Copyright © 2020 Shanka. All rights reserved.
//

#ifndef Gilt_hpp
#define Gilt_hpp
#include "date.h"
#include "calendar.h"
#include "error.h"
#include <stdio.h>
#include <cmath>
#include "Intermediary.hpp"
#include "Function.hpp"
class Gilt
{
private:
    double m_coupon;
    Date m_maturity;
public:
    Gilt(double coupon,Date maturity) :m_coupon(coupon),m_maturity(maturity){};
    double cleanPrice(Date settle,double ytm);
    double YieldToMaturity(Date settle,double clean);
    double cleanPrice_2(Date settle, double ytm);
    
};

#endif /* Gilt_hpp */
