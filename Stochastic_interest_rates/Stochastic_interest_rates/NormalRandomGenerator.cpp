//
//  NormalRandomGenerator.cpp
//  Stochastic_interest_rates
//
//  Created by Shankar on 15/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "NormalRandomGenerator.hpp"
#include <random>

using namespace std;
double NormalRandomGenerator:: rand_num_gen_1()
{
    double U1=((double) rand() / (RAND_MAX));
    return U1;
}
double NormalRandomGenerator:: rand_num_gen_2()
{
    double U2=((double) rand() / (RAND_MAX));
    return U2;
}

double NormalRandomGenerator::generate_z1()
{
    const double PI=3.141592653589793238463;
    double z1=sqrt(-2*log(rand_num_gen_1()))*cos(2*PI*rand_num_gen_2());
    return z1;
    
}
double NormalRandomGenerator::generate_z2()
{
    const double PI=3.141592653589793238463;
    double z2=sqrt(-2*log(rand_num_gen_1()))*sin(2*PI*rand_num_gen_2());
    return z2;
  
}
