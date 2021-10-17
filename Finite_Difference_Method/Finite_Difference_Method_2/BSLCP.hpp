//
//  BSLCP.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef BSLCP_hpp
#define BSLCP_hpp
#include "LCP.hpp"
#include "BSModel101.hpp"
#include "Option.hpp"
#include "BSEq_h.hpp"

class BSEqLCP: public LCP, public BSEq
{
   public:
      BSEqLCP(BSModel* PtrModel,Option* PtrOption)
         : BSEq(PtrModel,PtrOption){PtrPDE = this;}

      double g(double t,double z)
         {return PtrOption->Payoff(z);}
};

#endif /* BSLCP_hpp */
