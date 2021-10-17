//
//  HeatEq.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef HeatEq_hpp
#define HeatEq_hpp

#include "BSModel101.hpp"
#include "Option.hpp"
#include "ParabPDE.hpp"

class HeatEq: public ParabPDE
{
   public:
      BSModel* PtrModel;
      Option* PtrOption;
      HeatEq(BSModel* PtrModel_,Option* PtrOption_);

      double a(double t,double x){return -0.5;}
      double b(double t,double x){return 0.0;}
      double c(double t,double x){return 0.0;}
      double d(double t,double x){return 0.0;}

      double f(double x);
      double fl(double t);
      double fu(double t);

      double Z(double t,double x);
      double V(double t,double u);
      double X(double t,double z);
      double U(double t,double v);
};

#endif





