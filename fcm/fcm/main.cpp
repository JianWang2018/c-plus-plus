#include<stdio.h>
#include <malloc.h>
#include<math.h>
# pragma warning(disable:4996)
# include"fcm.h"
# include<fstream>
#include<vector>
// define function 1
double function1(double alpha, double x)
{
	double y = 0;
	y = fabs(alpha*x);
	return y;
}

//define function1
double function2(double alpha, double x)
{
	double y = 0;
	y = fabs(alpha*x) + x / 2 - pow(x, 2);
	return y;
}

//define function2
double function3(double alpha, double x)
{
	double y = 0;
	y = 1 / (1 + alpha*pow(x, 2));
	return y;
}

// define a function in single version

float single_function1(float alpha, float x)
{
	float y = 0;
	y = fabs(alpha*x);
	return y;
}

float single_function2(float alpha, float x)
{
	float y = 0;
	y = fabs(alpha*x) + x / 2 - pow(x, 2);
	return y;
}

float single_function3(float alpha, float x)
{
	float y = 0;
	y = 1 / (1 + alpha*pow(x, 2));
	return y;
}





int main()
{   //------------------------------------------------
////    first run the newton method
//    int n=10;
//    int N=1000;
//
//    double alpha = 2.0;
//
//
//    fcm res_newton;
//    res_newton.newton(n,N,alpha,function1);
//
//    return 0;
////-------------------------------------------------
// //now run the Bernstein method
//    int n=20;
//    int N=1000;
//
//    double alpha = 2.0;
//
//
//    fcm res_beinstein;
//    res_beinstein.beinstein(n,N,alpha,function1);
//------------------------------------------------------
// piecewise case:
//    int n=10;
//    int N=1000;
//    double alpha =2.0;
//    fcm res_piecewise;
//    res_piecewise.piecewise(n,N,alpha,function3);
//    return 0;
//-----------------------------------------------------------------
// run the piecewise method for the newton method

////    first run the newton method
	const int N = 1000;

	double alpha = 2.0;

	double x = 3.0;
	fcm res;
	vector<double> xx(N + 1);
	vector <double> diffCo(N + 1);
	res.newton1(N, xx, diffCo, alpha, function1);
	double y = res.newton2(x, xx, N, diffCo);
	cout<<y;

//---------------------------------------------------------------
//--------------------------------------------------------------
//for the single version

//    first run the newton method
//    int n=30;
//    int N=1000;
//
//    float alpha = 2.0;
//
//
//    fcm res_newton;
//    res_newton.single_newton(n,N,alpha,single_function1);
//
//    return 0;
//-------------------------------------------------
 //now run the Bernstein method
//     n=20;
//     N=1000;
//
//     alpha = 2.0;
//
//
//    fcm res_beinstein;
//    res_beinstein.single_beinstein(n,N,alpha,single_function1);
//------------------------------------------------------
 //piecewise case:
//    n=10;
//    N=1000;
//    alpha =2.0;
//    fcm res_piecewise;
//    res_piecewise.single_piecewise(n,N,alpha,single_function1);
//    return 0;

}

