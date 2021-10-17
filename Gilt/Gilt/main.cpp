//
//  main.cpp
//  Gilt
//
//  Created by Shankar on 04/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "date.h"
#include "calendar.h"
#include "error.h"
#include <stdio.h>
#include "Gilt.hpp"
using namespace std;
int main()
{
    unsigned int day,month,year;
    day=12;
    month=12;
    year=2013;
    Date settle(day,month,year);
    Date maturity(7,9,2039);
    Gilt g(4.25,maturity);
    cout<<"The clean price is: "<<g.cleanPrice(settle, 0.035385)<<endl;
    cout<<"The yield to maturity is: "<<g.YieldToMaturity(settle, 111.95)<<endl;
  
 
    
    
}
