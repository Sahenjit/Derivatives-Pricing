//
//  ParabPDE.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef ParabPDE_hpp
#define ParabPDE_hpp

class ParabPDE
{
   public:
      double T,xl,xu;

      virtual double a(double t, double x)=0;
      virtual double b(double t, double x)=0;
      virtual double c(double t, double x)=0;
      virtual double d(double t, double x)=0;

      virtual double f(double x)=0;
      virtual double fu(double t)=0;
      virtual double fl(double t)=0;
};


#endif /* ParabPDE_hpp */
