//
//  StoreFile.cpp
//  Eur_call
//
//  Created by Shankar on 29/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "StoreFile.hpp"
#include "Euro_call.hpp"
#include "EurPut.hpp"
#include <iostream>

Storefile::Storefile()
{
    
}
void Storefile::Readfile()
{
    string a;
    double b;
    double c;
    double d;
    ifstream myStream("text.txt");
    if(!myStream)
    {
        cout<<"Cannot open file"<<endl;
    }
    else if(myStream.is_open())
    {
        while(myStream>>a>>b>>c>>d)
        {
            s.push_back(a);
            e.push_back(b);
        
            if(a=="C")
            {
            EurOption *ptr=new EurCall(c,d);
                v.push_back(ptr);
            }
            else if(a=="P")
            {
                EurOption *ptr=new EurPut(c,d);
                v.push_back(ptr);
            }
        }
            
        
    }

}

void Storefile::Price_port()
{
    double S0=100;
    double interest=0.05;
    double sigma=0.25;
    for (int i=0;i<s.size();i++)
    {
        cout<<"option :"<<i+1<<endl;
        cout<<"Black scholes for porfolio: "<<(v[i]->PriceByBSFormula(S0,interest,sigma))*e[i]<<endl;
        cout<<"Vega for portflio: "<<v[i]->VegaByBSFormula(S0, sigma, interest)*e[i]<<endl;
        cout<<"Gamma for portfolio: "<<v[i]->DeltaByBSFormula(S0, sigma, interest)*e[i]<<endl;
        
    }
    
}
