//
//  Intermediary.hpp
//  Gilt
//
//  Created by Shankar on 15/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Intermediary_hpp
#define Intermediary_hpp
#include "Gilt.hpp"
#include "date.h"
#include "Function.hpp"
class Gilt;
class Intermediary:public Function
{
private:
    Date m_settle;
    Gilt *m_gilt;
public:
    Intermediary(Date settle,Gilt *g):m_settle(settle),m_gilt(g){};
    virtual double Value(double x) override;
    virtual double Deriv(double x) override;
    
};

#endif /* Intermediary_hpp */
