//
//  Histogram.hpp
//  Stochastic_interest_rates
//
//  Created by Shankar on 15/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Histogram_hpp
#define Histogram_hpp
#include <vector>
using namespace std;

class Histogram
{
private:
    double x_min;
    double x_max;
    int nbins;
    vector<double> x;
    vector<unsigned int> n;
public:
    Histogram(double x_min,double x_max,int nbins);
    void add(double a);
    void getResults(vector<double> &a,vector<unsigned int> &b);
    void writetostream(vector<double> &a,vector<unsigned int> &b);
    
};

#endif /* Histogram_hpp */
