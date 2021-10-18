//
//  Function.hpp
//  Stochastic Volatility
//
//  Created by Shankar on 24/04/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Function_hpp
#define Function_hpp

class Function
{
public:
    virtual double Value(double x)=0;
    virtual double Deriv(double x)=0;
};

#endif /* Function_hpp */
