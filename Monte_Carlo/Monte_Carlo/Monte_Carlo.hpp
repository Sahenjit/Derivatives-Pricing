//
//  Monte_Carlo.hpp
//  Monte_Carlo
//
//  Created by Shankar on 09/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Monte_Carlo_hpp
#define Monte_Carlo_hpp
#include "Stats1.hpp"
#include <cmath>
class Monte_Carlo:public Stats1
{
private:
    double h;
    double w;
   
    
public:
    Monte_Carlo(double h,double w);
    double generate_rand(double ,double);
    
};

#endif /* Monte_Carlo_hpp */
