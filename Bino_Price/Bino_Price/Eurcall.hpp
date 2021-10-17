//
//  Eurcall.hpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Eurcall_hpp
#define Eurcall_hpp
#include "Eur_Option.hpp"
#include "Bino_Price.hpp"
#include "American_Opt.hpp"
class Eurcall:public Euroption,public American_option
{
private:
    double K;
public:
    void SetK(double K_);
    int GetInputData();
    double Payoff(double);
};


#endif /* Eurcall_hpp */
