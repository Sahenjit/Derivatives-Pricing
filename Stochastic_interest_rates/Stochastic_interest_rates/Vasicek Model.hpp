//
//  Vasicek Model.hpp
//  Stochastic_interest_rates
//
//  Created by Shankar on 15/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Vasicek_Model_hpp
#define Vasicek_Model_hpp
#include "Histogram.hpp"
#include "NormalRandomGenerator.hpp"
#include <vector>
#include "Stats1.hpp"
#include <numeric>
class Vasicek_Model
{
private:
    typedef vector<double> SamplePath;
    double a;
    double b;
    double sigma;
    double r0;
    double T;
public:
    Vasicek_Model(double,double,double,double,double);
    double GenerateSamplePath(double,SamplePath &r);
    double PriceByMc(double);
    double Price_By_Mc_2(double,double,double);
    void Interest_rate_hist(double,double);
    double Payoff(SamplePath &r,double,double);

};

#endif /* Vasicek_Model_hpp */
