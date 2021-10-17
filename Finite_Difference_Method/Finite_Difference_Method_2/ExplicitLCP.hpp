//
//  ExplicitLCP.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef ExplicitLCP_hpp
#define ExplicitLCP_hpp

#include "ExplicitLCP.hpp"
#include "LCP.hpp"
#include "FDLCP.hpp"
#include "ExplicitMethod.hpp"

class ExplicitLCP: public ExplicitMethod, public FDLCP
{
   public:
      ExplicitLCP(LCP* PtrLCP_, int imax_, int jmax_)
         : ExplicitMethod(PtrLCP_->PtrPDE, imax_, jmax_)
      {
         PtrLCP = PtrLCP_;
         PtrFDMethod = this;
      }

      void SolveLCP();
};

#endif /* ExplicitLCP_hpp */
