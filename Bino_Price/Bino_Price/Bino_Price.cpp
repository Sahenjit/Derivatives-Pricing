//
//  Bino_Price.cpp
//  Bino_Price
//
//  Created by Shankar on 01/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Bino_Price.hpp"
#include <vector>
using namespace std;

int Bino_price::Getinputdata()
{
    cout<<"Enter S0: ";
    cin>>S0;
    cout<<"Enter U: ";
    cin>>U;
    cout<<"Enter D: ";
    cin>>D;
    cout<<"Enter R: ";
    cin>>R;
    
    cout<<endl;
    
    if(S0<=0.0 || U<=-1.0 ||D<=-1.0 ||U<=D || R<=-1.0)
    {
        cout<<"Illegal data ranges"<<endl;
        cout<<"Terminating program"<<endl;
        return 1;
    }
    if(R>=U || D>=R)
    {
        cout<<"Arbritage exists"<<endl;
        cout<<"Terminating program"<<endl;
    }
    cout<<"Input data checked"<<endl;
    cout<<"There is no arbritage"<<endl;
    return 0;
}
double Bino_price::getR()
{
    return R;
}
double Bino_price::S(int n,int i)
{
    return S0*pow(U,i)*pow(D,n-i);
}
double Bino_price::RiskNeutralProb()
{
    return ((R)-D)/(U-D);
}

