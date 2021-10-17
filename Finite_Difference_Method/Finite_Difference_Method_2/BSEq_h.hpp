//
//  BSEq_h.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef BSEq_h_hpp
#define BSEq_h_hpp
#include "ParabPDE.hpp"
#include "BSModel101.hpp"
#include "Option.hpp"

class BSEq: public ParabPDE
{
   public:
      BSModel* PtrModel;
      Option* PtrOption;
      BSEq(BSModel* PtrModel_,Option* PtrOption_);

      double a(double t, double z);
      double b(double t, double z);
      double c(double t, double z);
      double d(double t, double z);

      double f(double z);
      double fl(double t);
      double fu(double t);
};
#endif /* BSEq_h_hpp */
