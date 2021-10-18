//
//  LinearInterpolator.cpp
//  CourseWork2
//
//  Created by Shankar on 27/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "LinearInterpolator.hpp"

#include <iostream>



void LinearInterpolator::add(double x,double y)
{
    rates.insert(pair<double,double>(x,y));
}
double LinearInterpolator::value(double x)
{
   

    map<double,double>::iterator it_1=rates.begin();
    if(it_1->first>x)
        return it_1->second;
    map<double,double>::iterator it=rates.begin();
    for(;it!=rates.end();it++)
    {
       double upperlimit=it->first;
       
        if(x<upperlimit)
        {
            double xR=it->first;
            double yR=it->second;
           
        --it;
            double xL=it->first;
            double yL=(it)->second;
          
            
            double grad = (yR-yL)/(xR-xL);
            double y_val=yL+(x-xL)*grad;
            return y_val;
            
        }
       
            
    }
    --it;
    return it->second;
}
   
   

