//
//  Histogram.cpp
//  Stochastic_interest_rates
//
//  Created by Shankar on 15/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Histogram.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
Histogram::Histogram(double x_min,double x_max,int nbins)
{
    this->x_min=x_min;
    this->x_max=x_max;
    this->nbins=nbins;
    double bin_width=(x_max-x_min)/(nbins);
    double bin_intervals=x_min+bin_width;
    x.push_back(x_min);
    x.push_back(bin_intervals);
    n.push_back(0);
    n.push_back(0);
    for (int i=0;i<nbins-1;i++)
    {
            bin_intervals=bin_intervals+bin_width;
                this->x.push_back(bin_intervals);
                this->n.push_back(0);
        
    }
    x.pop_back();
    n.pop_back();
    
}

void Histogram::add(double a)
{
    
    for (int i=0;i<x.size();i++)
    {
        if(x[i]<=a && a<x[i+1])
        {
            n[i]++;
        }
        
    }
}

void Histogram::getResults(vector<double> &a, vector<unsigned int> &b)
{
    
    for (int i=0;i<x.size()+1;i++)
    {
        a.push_back(x[i]);
        b.push_back(n[i]);
        cout<<a[i]<<'\t'<<b[i]<<endl;
    }
}

void Histogram::writetostream(vector<double> &a, vector<unsigned int> &b)
{
           string inputFile = "Histogram.txt";
           string line;
           ofstream myStream(inputFile,ios::app);
           if(myStream.is_open())
           {
               cout<<"The file is open: ";
               cout<<endl;
              
           }
    for(unsigned int i=0;i<x.size()+1;i++)
    {
         myStream<<x[i]<<'\t'<<n[i]<<endl;
    }
}



