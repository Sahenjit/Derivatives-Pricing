//
//  Matrix.hpp
//  Finite_Difference_Method_2
//
//  Created by Shankar on 01/07/2020.
//  Copyright © 2020 Shankar. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <vector>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matrix;

Vector operator*(const Matrix& C,const Vector& V);
Vector operator*(const double& a,const Vector& V);
Vector operator+(const double& a,const Vector& V);
Vector operator+(const Vector& V,const Vector& W);
Vector operator*(const Vector& V,const Vector& W);
Vector exp(const Vector& V);
double operator^(const Vector& V,const Vector& W);

#endif /* Matrix_hpp */
