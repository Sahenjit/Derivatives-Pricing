//
//  Intermediary.cpp
//  Gilt
//
//  Created by Shankar on 15/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Intermediary.hpp"

double Intermediary::Value(double ytm)
{
    return m_gilt->cleanPrice(m_settle,ytm);
}

double Intermediary::Deriv(double ytm)
{
    return 0;
}
