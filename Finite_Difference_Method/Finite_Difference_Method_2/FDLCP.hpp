//
//  FDLCP.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef FDLCP_hpp
#define FDLCP_hpp

#include "FDMethod.hpp"
#include "LCP.hpp"

class FDLCP
{
   public:
      LCP* PtrLCP;
      FDMethod* PtrFDMethod;
      double g(int i,int j)
      {
         return PtrLCP->g(PtrFDMethod->t(i),PtrFDMethod->x(j));
      }
};


#endif /* FDLCP_hpp */
