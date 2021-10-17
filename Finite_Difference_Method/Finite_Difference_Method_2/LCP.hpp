//
//  LCP.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef LCP_hpp
#define LCP_hpp

#include "ParabPDE.hpp"
class LCP
{
   public:
      ParabPDE* PtrPDE;
      virtual double g(double t,double x)=0;
};

#endif /* LCP_hpp */
