//
//  Box_Muller.hpp
//  Box_Muller
//
//  Created by Shankar on 29/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Box_Muller_hpp
#define Box_Muller_hpp

class NormalRandomGenerator
{
private:
    double z1;
    double z2;
    double sum_z1=0;
    double sum_z2=0;
    double Counter=0;
    double sum_of_squares_z1=0;
    double sum_of_squares_z2=0;
public:
    void generate_z1(double x,double x1);
    void generate_z2(double x,double x1);
    void add_z1();
    void add_z2();
    double mean_z1();
    double mean_z2();
    double stDev_z1();
    double stDev_z2();
    
};

#endif /* Box_Muller_hpp */
