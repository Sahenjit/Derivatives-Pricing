//
//  EurPut.hpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef EurPut_hpp
#define EurPut_hpp
#include "Eur_Option.hpp"
#include "Bino_Price.hpp"
#include "American_Opt.hpp"

class EurPut:public Euroption,public American_option
{
private:
    double K;
public:
    void SetK(double);
    int GetInputData();
    double Payoff(double);
};

#endif /* EurPut_hpp */
