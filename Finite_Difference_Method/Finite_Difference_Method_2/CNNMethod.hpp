//
//  CNNMethod.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef CNNMethod_hpp
#define CNNMethod_hpp
#include "ImplicitMethod.hpp"

class CNMethod: public ImplicitScheme
{
   public:
      CNMethod(ParabPDE* PtrPDE_,int imax_,int jmax_)
         : ImplicitScheme(PtrPDE_, imax_, jmax_) {}

      double A(int i, int j)
         {return 0.5*dt*(b(i-0.5,j)/2.0-a(i-0.5,j)/dx)/dx;}
      double B(int i, int j)
         {return 1.0+0.5*dt*(2.0*a(i-0.5,j)/(dx*dx)-c(i-0.5,j));}
      double C(int i, int j)
         {return -0.5*dt*(b(i-0.5,j)/2.0+a(i-0.5,j)/dx)/dx;}
      double D(int i, int j){return -dt*d(i-0.5,j);}
      double E(int i, int j){return -A(i,j);}
      double F(int i, int j){return 2.0-B(i,j);}
      double G(int i, int j){return -C(i,j);}
};

#endif /* CNNMethod_hpp */
