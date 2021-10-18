//
//  Eur_call_MC.hpp
//  Jump_Diffusion
//
//  Created by Shankar on 06/05/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Eur_call_MC_hpp
#define Eur_call_MC_hpp
#include "Eur_Option.hpp"
#include <vector>
#include "Stats1.hpp"
typedef std::vector<double> SamplePath;

class Eur_call_MC
{
private:
    double T_;
    double K_;
    double S0;
public:
    Eur_call_MC();
    Eur_call_MC(double,double,double);
    double payoff(SamplePath &);
    void GenerateSamplePath(double T,int m,SamplePath &,double,double,double,double,double);
    double PricebyMc(double,double,double,double,double,double,double);
};
#endif /* Eur_call_MC_hpp */
