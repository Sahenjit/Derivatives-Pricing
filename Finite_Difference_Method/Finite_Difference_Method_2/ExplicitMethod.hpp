//
//  ExplicitMethod.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef ExplicitMethod_hpp
#define ExplicitMethod_hpp
#include "FDMethod.hpp"

class ExplicitMethod: public FDMethod
{
   public:
      ExplicitMethod(ParabPDE* PtrPDE_, int imax_, int jmax_)
         : FDMethod(PtrPDE_, imax_, jmax_) {}

      double A(int i, int j)
             {return dt*(b(i,j)/2.0-a(i,j)/dx)/dx;}
      double B(int i, int j)
             {return 1.0-dt*c(i,j)+2.0*dt*a(i,j)/(dx*dx);}
      double C(int i, int j)
             {return -dt*(b(i,j)/2.0+a(i,j)/dx)/dx;}
      double D(int i, int j)
             {return -dt*d(i,j);}

      void SolvePDE();
};
#endif /* ExplicitMethod_hpp */
