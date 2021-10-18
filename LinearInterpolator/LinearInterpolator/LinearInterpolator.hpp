//
//  LinearInterpolator.hpp
//  CourseWork2
//
//  Created by Shankar on 27/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef LinearInterpolator_hpp
#define LinearInterpolator_hpp
#include <iterator>
#include <map>

using namespace std;
class LinearInterpolator
{
private:
    map<double, double> rates;
public:
    void add(double x,double y);
    double value(double x);
    void print();
    
};

#endif /* LinearInterpolator_hpp */
