//
//  main.cpp
//  CourseWork2
//
//  Created by Shankar on 27/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "LinearInterpolator.hpp"
#include <iostream>


using namespace std;
void swapargs(double &x,double &y)
{
    int temp=x;
    x=y;
    y=temp;
    
}


int main()
{
    
    LinearInterpolator L1;
    L1.add(1.0,1.19);
    L1.add(2.0,1.86);
    L1.add(3.0,2.34);
    L1.add(4.0,2.56);
    L1.add(5.0,2.63);
    
    //cout<<L1.value(2);
    //cout<<L1.value(4.5);
    
  
    }
