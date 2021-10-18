//
//  Monte_Carlo.cpp
//  Monte_Carlo
//
//  Created by Shankar on 09/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Monte_Carlo.hpp"
#include <iostream>

using namespace std;

Monte_Carlo::Monte_Carlo(double h,double w)
{
    this->h=h;
    this->w=w;
}

double Monte_Carlo::generate_rand(double x, double y)
{
    
    double r=sqrt(pow(x,2)+pow(y,2));
    double theta=atan(y/x);
    double count =1;
    double no_of_elements;
    
    if(r<=(3-cos(8*theta)))
    {
        Stats1::add(count);
        
    }
    else
    {
        no_of_elements=Stats1::get_number_of_elements();
    }
   
    
    double Area_of_s=h*w;
    double area=Area_of_s*Stats1::mean();
    return area;
}
