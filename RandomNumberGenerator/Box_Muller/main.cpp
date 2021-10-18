//
//  main.cpp
//  Box_Muller
//
//  Created by Shankar on 29/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <random>
#include "Box_Muller.hpp"
using namespace std;

int main()
{
    NormalRandomGenerator n;
    
    for (int i=0;i<10000000;i++)
    {
        double U1=((double) rand() / (RAND_MAX));
        double U2=((double) rand() / (RAND_MAX));
    
        n.generate_z1(U1,U2);
        n.generate_z2(U1,U2);
        n.add_z1();
        n.add_z2();
    }
   
    cout<<"The mean calculated from z1 is as follows: "<<n.mean_z1()<<endl;
    cout<<"The mean calculated from z2 is as follows: "<<n.mean_z2()<<endl;
    cout<<"The Standard deviation from z1 is as follows: "<<n.stDev_z1()<<endl;
    cout<<"The Standrd deviation from z2 is as follows: "<<n.stDev_z2()<<endl;
    
    
}
