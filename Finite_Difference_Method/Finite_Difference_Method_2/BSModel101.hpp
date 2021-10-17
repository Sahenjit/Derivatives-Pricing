//
//  BSModel101.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 28/06/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef BSModel101_hpp
#define BSModel101_hpp
#include <vector>
using namespace std;

typedef vector<double> SamplePath;

class BSModel
{

public:
      double S0, r, sigma;
      BSModel(double S0_, double r_, double sigma_) {S0 = S0_; r = r_; sigma = sigma_;srand(time(NULL));}
      void GenerateSamplePath(double T,int m,SamplePath& S);
};
#endif /* BSModel101_hpp */
