//
//  Stats1.hpp
//  Stats1
//
//  Created by Shankar on 24/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Stats1_H
#define Stats1_H


class Stats1
{
private:
    double sum=0;
    double number_of_elements=0;
    double Sum_of_squares=0;
 
    
public:
    double get_number_of_elements();
    double get_sum();
    void add(const double x);
    double mean();
    double stDev();
};
#endif

