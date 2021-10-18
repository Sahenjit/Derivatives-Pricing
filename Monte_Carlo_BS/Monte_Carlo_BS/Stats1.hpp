//
//  Stats1.hpp
//  BSModel
//
//  Created by Shankar on 25/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Stats1_hpp
#define Stats1_hpp

class Stats1
{
private:
    double sum=0;
    double number_of_elements=0;
    double Sum_of_squares=0;
 
    
public:
    double get_number_of_elements();
    double get_sum();
    void add(double x);
    double mean();
    double stDev();
};

#endif /* Stats1_hpp */
