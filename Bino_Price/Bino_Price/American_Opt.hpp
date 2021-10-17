//
//  American_Opt.hpp
//  Bino_Price
//
//  Created by Shankar on 02/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef American_Opt_hpp
#define American_Opt_hpp
#include "Bino_Price.hpp"
class American_option
{
private:
    int N;
public:
    void SetN(int N_);
    virtual double Payoff(double z)=0;
    double PricebySnell(Bino_price Model);
};

#endif /* American_Opt_hpp */
