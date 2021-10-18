//
//  main.cpp
//  Histogram
//
//  Created by Shankar on 28/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//
#include "Histogram.hpp"
#include <iostream>
#include <random>
#include "NormalRandomGenerator.hpp"
#include <fstream>
using namespace std;
int main()
{
    //mt19937 RandomEngine(0);
    //uniform_real_distribution<double> unif(0, 1);
    Histogram h(-4,4,1000);
    NormalRandomGenerator nrg;

    for(int i=0;i<1e6;++i)
    {
        double r=nrg.generate_z1();
        h.add(r);
    }
    vector<double> a;
    vector<unsigned int> b;
    h.getResults(a,b);
    h.writetostream(a,b);

    return 0;
}
