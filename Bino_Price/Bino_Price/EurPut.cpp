//
//  EurPut.cpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "EurPut.hpp"

using namespace std;

int EurPut::GetInputData()
{
   cout << "Enter put option data:" << endl;
   int N;
   cout << "Enter steps to expiry N: ";
   cin >> N;
   Euroption::SetN(N);American_option::SetN(N);
   cout << "Enter strike price K: ";
    cin>>K;
   cout << endl;
   return 0;
}
double EurPut::Payoff(double z)
{
if (K>z)
    {
    return K-z;
    }
    else
    {
        return 0;
    }
}
