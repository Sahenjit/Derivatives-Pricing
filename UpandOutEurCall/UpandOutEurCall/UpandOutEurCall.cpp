//
//  UpandOutEurCall.cpp
//  UpandOutEurCall
//
//  Created by Shankar on 19/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//
#include <iostream>
#include "UpandOutEurCall.hpp"
#include <vector>
using namespace std;
double UpandOutEurcall::N(double x)
{
    double gamma = 0.2316419;     double a1 = 0.319381530;
    double a2    =-0.356563782;   double a3 = 1.781477937;
    double a4    =-1.821255978;   double a5 = 1.330274429;
    double pi    = 4.0*atan(1.0); double k  = 1.0/(1.0+gamma*x);
    if (x>=0.0)
        {
            return 1.0-((((a5*k+a4)*k+a3)*k+a2)*k+a1)*k*exp(-x*x/2.0)/sqrt(2.0*pi);
        }
           else return 1.0-N(-x);
}
UpandOutEurcall::UpandOutEurcall()
{
}
double UpandOutEurcall::d_plus(double x,double interest,double sigma,double t)
{
    double d_p=(log(x)+(interest+(pow(sigma,2)/2*t)))/((sigma*sqrt(t)));
    return d_p;
}
double UpandOutEurcall::PricebyBSFormula(double stock_price,double strike_price,double barrier,double interest,double sigma,double t)
{
    double e1=d_plus(stock_price/strike_price, interest, sigma, t);
    double e2=e1-(sigma*sqrt(t));
    double e3=d_plus(stock_price/barrier, interest, sigma, t);
    double e4=e3-(sigma*sqrt(t));
    double e5=d_plus(stock_price/barrier, -interest, sigma, t);
    double e6=e5-(sigma*sqrt(t));
    double e7=d_plus((stock_price*strike_price/(pow(barrier, 2))), -interest, sigma, t);
    double e8=e7-(sigma*sqrt(t));
    double sub1=(pow((barrier/stock_price),(1+(2*interest)/(sigma*sigma)))*(N(e6)-N(e8)));
    double sub2=(pow((barrier/stock_price),(-1+(2*interest)/(sigma*sigma)))*(N(e5)-N(e7)));
    double price =(stock_price*(N(e1)-N(e3)-sub1))-(strike_price*exp(-interest*t)*(N(e2)-N(e4)-sub2));
    
    return price;
 
}

double UpandOutEurcall::CallPayoff(double z, double k,double barrier)
{
    if(z>k && z<barrier)
    {
        return z-k;
    }
    else
    {
        return 0;
    }
}
double UpandOutEurcall::PricebyCRR(double stock_price, double U, double D, double interest,int no_of_steps,double K,double barrier)
{
    if(stock_price<=0 || U<=-1.0 ||D<=-1.0 ||U<=D ||interest<=-1.0)
    {
        cout<<"Illegal data ranges"<<endl;
        cout<<"Terminating program"<<endl;
        return 1;
    }
    if(interest>=U || interest<=D)
    {
        cout<<"Arbitage exists"<<endl;
        cout<<"Terminating program"<<endl;
        return 1;
    }
    vector<double>Price(no_of_steps+1);
   
    for (int i=0;i<=no_of_steps;i++)
    {
        
        
        Price[i]=CallPayoff(BinModel::S(stock_price,U,D,no_of_steps,i),K,barrier);
       
    
    }
    for (int n=no_of_steps;n>0;n--)
             
    {
        for (int i=0;i<=no_of_steps-1;i++)
        {
            Price[i]=(BinModel::RiskNeutProb(U,D,interest)*Price[i+1]+(1-BinModel::RiskNeutProb(U,D,interest))*Price[i])/(interest);
          
         
        }
    }
    return Price[0];
}
