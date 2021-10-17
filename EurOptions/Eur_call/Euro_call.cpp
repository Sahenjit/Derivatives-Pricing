//
//  Euro_call.cpp
//  Eur_call
//
//  Created by Shankar on 10/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Euro_call.hpp"
#include <cmath>

using namespace std;

EurCall::EurCall(double K_,double T_):EurOption(K_,T_)
{
    
}
double EurCall::DeltaByBSFormula(double S0,double sigma,double r)
{
    return EurOption::N(d_plus(S0,sigma,r));
}

double EurCall::PriceByBSFormula(double S0,double sigma, double r)
{
   return S0*EurOption::N(d_plus(S0,sigma,r))-K_*exp(-r*T_)*EurOption::N(d_minus(S0,sigma,r));
}
double EurCall::GammaByBSFormula(double S0,double sigma,double r)
{
    
     return (exp(-(d_plus(S0,sigma,r)*d_plus(S0,sigma,r))/2)/(S0*sigma*sqrt(T_)*sqrt(2*3.1415)));
}
double EurCall::payoff(double ST, double K)
{
    if (ST>K)
    {
        return ST-K;
    }
    else
        return 0;
}
double EurCall::PriceByCRR(double stock_price, double U, double D, double interest, int no_of_steps, double K)
{
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
                
                
                Price[i]=payoff(EurOption::stock_movement(stock_price,U,D,no_of_steps,i),K);
               
            
            }
            for (int n=no_of_steps;n>0;n--)
                     
            {
                for (int i=0;i<=no_of_steps-1;i++)
                {
                    Price[i]=(EurOption::RiskNeutralProb(U,D,interest)*Price[i+1]+(1-EurOption::RiskNeutralProb(U,D,interest))*Price[i])/(interest);
                  
                 
                }
            }
            return Price[0];
        }
}


double EurCall::PricebyTrinomial(double stock_price, double r, int no_of_steps, double K,double time_step,double sigma)
    
    {
        double lambda=2;
        if(stock_price<=0 ||r<=-1.0)
        {
            cout<<"Illegal data ranges"<<endl;
            cout<<"Terminating program"<<endl;
            return 1;
        }
        double M=exp(r*time_step);
        double V=((exp(2*(r*time_step)))*(exp(pow(sigma,2)*time_step)-1));
        double u=exp(lambda*(sigma*sqrt(time_step)));
        double d=1/u;
        double qu=(((V+pow(M,2)-M)*u)-(M-1))/((u-1)*(pow(u,2)-1));
        double qd=((pow(u,2)*(V+pow(M,2)-M))-pow(u,3)*(M-1))/((u-1)*(pow(u,2)-1));
        double qm=1-qu-qd;
        double interest=exp(r*time_step);
       
        vector<double>Price;
        for(int i=0;i<2*(no_of_steps)+1;i++)
        {
            Price.push_back(0);
        }
        for (int i=0;i<=(2*(no_of_steps)+1)/2;i++)
        {

            Price[i]=payoff(EurOption::stock_movement_up(stock_price,u,i,no_of_steps),K);
        }
        for (int i=0;i<Price.size();i++)
        {
            if (Price[i]==0)
                {
                    Price[i]=payoff(EurOption::stock_movement_down(stock_price,d, i, no_of_steps),K);
                }
        }
        for (int n=no_of_steps;n>0;n--)
                 
        {
            for (int i=0;i<=2*(no_of_steps-1)+1;i++)
            {
                Price[i]=(qu*Price[i]+qm*Price[i+1]+qd*Price[i+2])/interest;
             
            }
        }
        return Price[0];
    }



