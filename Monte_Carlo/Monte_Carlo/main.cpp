//
//  main.cpp
//  Monte_Carlo
//
//  Created by Shankar on 09/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include <random>
#include "Monte_Carlo.hpp"
using namespace std;
int main()
{
    Monte_Carlo c(8,8);
    double last_value;
    for (int i=0;i<10000;i++)
    {
        double x = (rand() / (double)RAND_MAX)*8-4;
        double y = (rand() / (double)RAND_MAX)*8-4;
        last_value=c.generate_rand(x, y);
    }
    cout<<"This is the last value of the simulation: "<<last_value<<endl;
}
