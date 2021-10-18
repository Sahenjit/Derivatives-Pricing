//
//  UpandOutEurCall.hpp
//  UpandOutEurCall
//
//  Created by Shankar on 19/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef UpandOutEurCall_hpp
#define UpandOutEurCall_hpp
#include "BinModel.hpp"
#include <cmath>
class UpandOutEurcall:public BinModel
{
public:
    UpandOutEurcall();
    UpandOutEurcall(double ,double ,double ,double ,double ,double);
    double N(double);
    double d_plus(double,double,double,double);
    double PricebyBSFormula(double,double,double,double,double,double);
    double PricebyCRR(double,double,double,double,int,double,double);
    double CallPayoff(double,double,double);
    
};

#endif /* UpandOutEurCall_hpp */
