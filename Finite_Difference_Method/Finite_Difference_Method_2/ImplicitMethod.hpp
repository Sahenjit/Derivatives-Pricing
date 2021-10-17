//
//  ImplicitMethod.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef ImplicitMethod_hpp
#define ImplicitMethod_hpp

#include "FDMethod.hpp"
#include "Matrix.hpp"

class ImplicitScheme: public FDMethod
{
   public:
      ImplicitScheme(ParabPDE* PtrPDE_,int imax_,int jmax_)
         : FDMethod(PtrPDE_, imax_, jmax_){}

      virtual double A(int i, int j)=0;
      virtual double B(int i, int j)=0;
      virtual double C(int i, int j)=0;
      virtual double D(int i, int j)=0;
      virtual double E(int i, int j)=0;
      virtual double F(int i, int j)=0;
      virtual double G(int i, int j)=0;

      Vector w(int i);
      Vector A(int i, Vector q);

      Vector LUDecomposition(int i,Vector q);

      void SolvePDE();
};

#endif /* ImplicitMethod_hpp */
