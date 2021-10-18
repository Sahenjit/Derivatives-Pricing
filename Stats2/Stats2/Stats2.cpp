//
//  Stats2.cpp
//  Stats2
//
//  Created by Shankar on 26/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Stats2.hpp"
#include <iostream>
#include <cmath>
#include <random>
#include <time.h>


using namespace std;

void Stats2:: add(double x,double y)
{
    sum_xy=sum_xy+(x*y);
    sum_x=sum_x+x;
    sum_y=sum_y+y;
    Counter++;
    sum_of_squares_x=sum_of_squares_x+(x*x);
    sum_of_squares_y=sum_of_squares_y+(y*y);
}

    
    
double Stats2:: mean_x()
{
    double avg_x=(sum_x/Counter);
    return avg_x;
}
double Stats2:: mean_y()
{
    double avg_y=(sum_y/Counter);
    return avg_y;
}

double Stats2:: covariance()
{
    double coVar;
    coVar=(sum_xy/Counter)-(mean_x()*mean_y());
    return coVar;
}

double Stats2::variance_x()
{
    double variance_x=(sum_of_squares_x/Counter)-pow(mean_x(),2);
    return variance_x;
}
double Stats2::variance_y()
{
    double variance_y=(sum_of_squares_y/Counter)-pow(mean_y(),2);
    return variance_y;
}
double Stats2:: correlation()
{
    double corr=covariance()/(sqrt(variance_x()*variance_y()));
    return corr;
}

double Stats2:: gradient()
{
    double grad=covariance()/variance_x();
    return grad;
}
double Stats2:: intercept()
{
    double inter=mean_y()-(gradient()*mean_x());
    return inter;
}


int main()
{
   
   
    Stats2 s2;
    s2.add(1,16);
    s2.add(2,11);
    s2.add(3,9);
    s2.add(4,3);
    s2.add(5,2);
    cout<<"The covariance is the following: "<<s2.covariance()<<endl;
    cout<<"The correlation is the following: "<<s2.correlation()<<endl;
    cout<<"The gradient is the following: "<<s2.gradient()<<endl;
    cout<<"The y_intercept is as follows: "<<s2.intercept()<<endl;
    cout<<"The formula for the equation of the line is as follow: "<< "y= "<<s2.gradient()<<"x+"<<s2.intercept()<<endl;
    

    
    
}
