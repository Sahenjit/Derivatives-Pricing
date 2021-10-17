//
//  Eur_Option.hpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Eur_Option_hpp
#define Eur_Option_hpp
#include "Bino_Price.hpp"
class Euroption
{
private:
    int N;
public:
    void SetN(int N_);
    virtual double Payoff(double z)=0;
    double PricebyCRR(Bino_price Model);
};


#endif /* Eur_Option_hpp */
