//
//  BSModel.hpp
//  BSModel
//
//  Created by Shankar on 24/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef BSModel_hpp
#define BSModel_hpp
#include <vector>
using namespace std;

typedef vector<double> SamplePath;

class BSModel
{
private:
    double S0;
    double r;
    double sigma;
public:
    BSModel();
    BSModel(double,double,double);
    void GenerateSamplePath(double,int,SamplePath &);
    double getr();
    double getS0();
    double getsigma();
};

#endif /* BSModel_hpp */
