//
//  Option.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Option_hpp
#define Option_hpp
#include "BSModel101.hpp"
class Option
{
   public:
      double T, zl, zu;
      virtual double Payoff(double z)=0;
      virtual double UpperBdCond
         (BSModel* PtrModel, double t)=0;
      virtual double LowerBdCond
         (BSModel* PtrModel, double t)=0;
};

class Put: public Option
{
   public:
      double K;
      Put(double K_, double T_, double zl_, double zu_)
         {K=K_; T=T_; zl=zl_; zu=zu_;}
      double Payoff(double z);
      double UpperBdCond(BSModel* PtrModel, double t);
      double LowerBdCond(BSModel* PtrModel, double t);
};


#endif /* Option_hpp */
