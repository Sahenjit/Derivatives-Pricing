//
//  Solver_02.hpp
//  Interest_Rate_Swaps
//
//  Created by Shankar on 28/08/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Solver_02_hpp
#define Solver_02_hpp

class Function
{
   public:
      virtual double Value(double x)=0;
};
double SolveByBisect(Function* Fct,double Tgt, double LEnd, double REnd, double Acc)
{
    double left=LEnd, right=REnd, mid=(left+right)/2;
    double y_left=Fct->Value(left)-Tgt, y_mid=Fct->Value(mid)-Tgt; while (mid-left>Acc)
{
           if ((y_left>0 && y_mid>0)||(y_left<0 && y_mid<0))
                {left=mid; y_left=y_mid;}
           else right=mid; mid=(left+right)/2; y_mid=Fct->Value(mid)-Tgt;
}
        return mid;
    
}



#endif /* Solver_02_hpp */
