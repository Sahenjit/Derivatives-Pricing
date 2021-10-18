//
//  BS_Model.hpp
//  Stochastic Volatility
//
//  Created by Shankar on 31/03/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef BS_Model_hpp
#define BS_Model_hpp
#include <vector>
using namespace std;

typedef vector<double> SamplePath;
typedef vector <double> Volatility;
class BSModel
{
private:
    double S0;
    double r;
    double a;
    double eta;
    double v_mean;
    double V0;
    double correlation;
public:
    BSModel();
    BSModel(double,double,double,double,double,double,double);
    void EulerScheme(Volatility & v,double,double);
    void GenerateSamplePath(double,int,SamplePath &,Volatility &);
    void test_vec(Volatility &);
    double Z1();
    double Z2(double);
    double E2();
    double getr();
    double getS0();
    double getsigma();
};
#endif /* BS_Model_hpp */
