//
//  FDMethod.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef FDMethod_hpp
#define FDMethod_hpp

#include <vector>
#include "ParabPDE.hpp"
using namespace std;
typedef vector<double> Vector;

class FDMethod
{
   public:
      ParabPDE* PtrPDE;
      int imax, jmax;
      double dx, dt;

      vector<Vector> V;

      FDMethod(ParabPDE* PtrPDE_, int imax_, int jmax_);

      double t(double i){return dt*i;}
      double x(int j){return PtrPDE->xl+dx*j;}

      double a(double i,int j){return PtrPDE->a(t(i),x(j));}
      double b(double i,int j){return PtrPDE->b(t(i),x(j));}
      double c(double i,int j){return PtrPDE->c(t(i),x(j));}
      double d(double i,int j){return PtrPDE->d(t(i),x(j));}

      double f (int j){return PtrPDE->f(x(j));}
      double fu(int i){return PtrPDE->fu(t(i));}
      double fl(int i){return PtrPDE->fl(t(i));}

      double v(double t,double x);
};

#endif /* FDMethod_hpp */
