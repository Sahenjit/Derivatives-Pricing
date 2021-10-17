//
//  Bino_Price.hpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Bino_Price_hpp
#define Bino_Price_hpp
#include <iostream>
#include <cmath>
class Bino_price
{
private:
    double S0;
    double U;
    double D;
    double R;
public:

    double RiskNeutralProb();
    double S(int, int i);
    int Getinputdata();
    double getR();
    
};

#endif /* Bino_Price_hpp */
