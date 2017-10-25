#ifndef FCM_H_INCLUDED
#define FCM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class fcm{
public:
    double newton(int n , int N, double alpha,double (*func)(double,double));
    float single_newton(int n, int N,float alpha,float(*func)(float,float));
    double combination(int n, int k);
    float single_combination(int n, int k);
    double beinstein(int n , int N, double alpha,double (*func)(double,double));
    float single_beinstein(int n , int N, float alpha,float (*func)(float,float));

    double piecewise(int n , int N, double alpha,double (*func)(double,double));
    float single_piecewise(int n , int N, float alpha,float (*func)(float,float));

    void newton1 (int N, vector <double >xx, vector <double> difCo,double alpha, double (*func)(double,double));
    double newton2 (double x, vector<double> xx, int N, vector <double > difCo);
    double piecewise2(double x , int s, int N, vector<double> xx, double alpha, double(*func)(double,double));



};

#endif // FCM_H_INCLUDED
