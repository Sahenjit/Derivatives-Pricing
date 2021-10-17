//
//  main.cpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "Bino_Price.hpp"
#include "Eur_Option.hpp"
#include "Eurcall.hpp"
#include "EurPut.hpp"
using namespace std;

int main()
{
    Bino_price Model;
    if (Model.Getinputdata()==1) return 1;
    Eurcall Option1;
    Option1.GetInputData();
    cout << "European call option price = "<< Option1.PricebyCRR(Model)<< endl;
    cout<<"American call option price  = "<<Option1.PricebySnell(Model)<<endl;
    EurPut Option2;
    Option2.GetInputData();
    cout << "European put option price = "<< Option2.PricebyCRR(Model) << endl;
    cout<<"American put option price  = "<<Option2.PricebySnell(Model)<<endl;
    return 0;
    
}
   
