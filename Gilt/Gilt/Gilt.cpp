//
//  Gilt.cpp
//  Gilt
//
//  Created by Shankar on 04/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#include "Gilt.hpp"
double SolveByBisect(Function *Fct,double Tgt,double LEnd,double REnd,double Acc)
{
    double left=LEnd, right=REnd, mid=(left+right)/2;
    double y_left=Fct->Value(left)-Tgt,y_mid=Fct->Value(mid)-Tgt;
    while(mid-left>Acc)
    {
        if((y_left>0 && y_mid>0) ||( y_left<0 && y_mid<0))
            {
                (left=mid);
                (y_left=y_mid);
            }
        else right=mid;
        mid=(left+right)/2;
        y_mid=Fct->Value(mid)-Tgt;
    }
    return mid;
}


double Gilt::cleanPrice(Date settle,double ytm)
{
    double no_of_coupon_payments=2.0;
    double count=0;
    double previous_coupon_date;
    Date temp_date=m_maturity;
    while(temp_date.daysDiff(settle)>0)
    {
        previous_coupon_date=temp_date.addMonths(-6);
        ++count;
    }
    --count;
    double r=settle.daysDiff(temp_date);
    double next_coupon_date=temp_date.addMonths(6);
    double s=next_coupon_date-previous_coupon_date;
    double m=temp_date.daysDiff(settle);
    double n=count;
    double accrued_interest=(r/s)*(m_coupon/no_of_coupon_payments);
    double sum=0;
    for (int i=0;i<=n;i++)
        {
            double first_section=((m_coupon/2.0)/pow(1+(ytm/2),i));
            sum=sum+(first_section);
        }
    sum=(100.0/pow(1+(ytm/2),n))+sum;
    double clean_price=(sum/pow(1+(ytm/2),(m)/s))-accrued_interest;
    return clean_price;
}

double Gilt::YieldToMaturity(Date settle, double clean)
{
    Intermediary im(settle,this);
    
    
    return SolveByBisect(&im, clean, 0, 1, 0.00000001);
}
