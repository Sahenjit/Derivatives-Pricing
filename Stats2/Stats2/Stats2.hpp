//
//  Stats2.hpp
//  Stats2
//
//  Created by Shankar on 26/01/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Stats2_hpp
#define Stats2_hpp

class Stats2
{
private:
    int Counter=0;
    double sum_xy=0;
    double sum_x=0;
    double sum_y=0;
    double sum_of_squares_x=0;
    double sum_of_squares_y=0;
    
    
public:
    void add(double x, double y);
    double mean_x();
    double mean_y();
    double Stdev();
    double covariance();
    double correlation();
    double variance_x();
    double variance_y();
    double gradient();
    double intercept();
    
};



#endif /* Stats2_hpp */
