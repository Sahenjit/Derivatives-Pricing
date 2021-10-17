//
//  main.cpp
//  Advanced computing - Date
//
//  Created by Shankar on 03/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include <iostream>
#include "basic.hpp"
#include "date.hpp"
using namespace std;
int main()
{
    Date dt(2,12,2005);
    Date dt1(2,2,2000);
    cout<< dt.weekday()<<endl;
    dt.addDays(0);
    dt.addMonths(0);
    dt.addYear(0);
    unsigned int d=0,m=0,y=0;
    dt.getDMY(d,m,y);
    cout<<d<<'/'<<m<<'/'<<y<<endl;
    double m_serial=dt.Daysdiff(dt1);
    cout<<m_serial<<": "<<"days difference"<<endl;

}
