//
//  Trap.cpp
//  Trapozodial
//
//  Created by Shankar on 11/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Trap.hpp"

DefInt::DefInt():Eurcall(),Eurput()
{
    a=0;
    b=0;
    N=0;
}
DefInt::DefInt(double a,double b,double interest,double t,double strike_price):Eurcall(a, strike_price),Eurput(a,strike_price)
{
    this->a=a;
    this->b=b;
    this->interest=interest;
    this->t=t;
    this->strike_price=strike_price;
    N=100;
    h=(b-a)/N;
}


double DefInt::calc_mean(double stock_price,double interest,double t,double sigma)
{
    mean=log(stock_price)+(interest*t)-((sigma*sigma)/2)*t;
    return mean;
}
double DefInt::calc_st_Dev(double sigma,double t)
{
    st_Dev=sigma*sqrt(t);
    return st_Dev;
}


double DefInt::lognormal(double a,double b)
{
    double sum=0;
    
    double first_term=(1/(a*st_Dev*sqrt(2*3.14159))*exp((-(log(a)-mean)*(log(a)-mean))/(2*st_Dev*st_Dev)))*Eurcall::payoff_call(a);
    //cout<<"This is the first term: "<<first_term;
    double last_term=(1/(b*st_Dev*sqrt(2*3.14159))*exp((-(log(b)-mean)*(log(b)-mean))/(2*st_Dev*st_Dev)))*Eurcall::payoff_call(b);
    //cout<<"This is the last term: "<<last_term<<endl;
    for (int i=0;i<=N-1;i++)
    {
        double second_term=(1/((a+(i*h))*st_Dev*sqrt(2*3.14159))*exp((-(log(a+(i*h))-mean)*(log(a+(i*h))-mean))/(2*st_Dev*st_Dev)))*(Eurcall::payoff_call(a+(i*h)));
        //cout<<"These are the iterations: "<<i<<endl<<"These are the second terms: "<<second_term<<endl<<"This is the Euro_payoff_call: "<<Eur_payoff_call(a+(i*h))<<endl;
            sum=sum+(2*second_term);
    }
    double trap_intergration=0.5*h*(first_term+last_term+sum);
    double option_price=exp(-interest*t)*trap_intergration;
    //cout<<"This is option price: "<<option_price;
    return option_price;
   
    
}


