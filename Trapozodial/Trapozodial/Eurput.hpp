//
//  Eurput.hpp
//  Trapozodial
//
//  Created by Shankar on 15/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Eurput_hpp
#define Eurput_hpp
#include <iostream>
#include <cmath>

using namespace std;
class Eurput
{
protected:
    double a;
    double strike_price;
public:
    Eurput();
    Eurput(double,double);
    double payoff_put(double);
};

#endif /* Eurput_hpp */
