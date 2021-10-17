//
//  StoreFile.hpp
//  Eur_call
//
//  Created by Shankar on 29/02/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef StoreFile_hpp
#define StoreFile_hpp
#include "EurOption.hpp"
#include <vector>
#include <cstring>
#include <fstream>
class Storefile
{
private:
    vector<string> s;
    vector<double> e;
    vector<EurOption*> v;
public:
    Storefile();
    void Readfile();
    void Price_port();
    
};


#endif /* StoreFile_hpp */
