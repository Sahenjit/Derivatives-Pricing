//
//  date.cpp
//  Advanced computing - Date
//
//  Created by Shankar on 03/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "date.hpp"
#include "basic.hpp"
#include <iostream>
#include <cmath>
using namespace std;
Date::Date(unsigned int d, unsigned int m,unsigned y)
{
    m_serial=DMY_to_serial(d,m,y);
    
}
void Date::addDays(int d)
{
    m_serial+=d;
   
}
void Date::addMonths(int m)
{
    unsigned int day=0,month=0,year=0;
    serial_to_DMY(m_serial,day,month,year);
    int newMonth=month+m;
    if(newMonth<1 || newMonth>12)
    {
    int n=floor(newMonth-1.0)/12.0;
    newMonth-=12*n;
    year+=n;
    }
    if (day<month)
    {
        
    }
    m_serial=DMY_to_serial(day,newMonth,year);
}
void Date::addYear(int y)
{
    if(y<0)
    {
       unsigned int day=0,month=0,year=0;
        serial_to_DMY(m_serial, day,month,year);
        int newYear=year+y;
        m_serial=DMY_to_serial(day,month,newYear);
    }
    else if(y>0)
    {
    unsigned int day=0,month=0,year=0;
    serial_to_DMY(m_serial, day,month,year);
    int newYear=year+y;
    m_serial=DMY_to_serial(day,month,newYear);
    }
    
}
double Date::Daysdiff(Date dt)
{
     double x=m_serial;
    if(m_serial<dt.m_serial)
    {
        m_serial=abs(x-dt.m_serial);
        double y=m_serial;
        double m_serial=0;
        m_serial=-y;
        return m_serial;
    }
    else
    {
    m_serial=abs(x-dt.m_serial);
    return m_serial;
    }
}
 Weekday Date::weekday()
    {
      
        return Weekday(m_serial%7);
        
    }
    bool Date::IsGbd()
    {
       
        {
            return false;
        }
    }
void Date::getDMY(unsigned int &d,unsigned int &m,unsigned int &y)
{
    serial_to_DMY(m_serial,d,m,y);
}
