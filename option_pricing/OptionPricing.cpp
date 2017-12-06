/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
# include <cmath>
# include<algorithm>
# include<vector>
#include<iostream>
#include"OptionPricing.h"
using namespace std;

/*
 * 
 */
double  OptionPricing::pay_off_straddle(double s, double k1, double k2){
//    @param s: current stock price
//    @param k1: in straddle option, the strike price of call option
//    @param k2: in straddle option, the strike price of put option
//    @return: pay off of straddle option 
    
    double res;
    
    if (s> k2)
        {
             res= s - k2;
        }
    else if(s < k1)
        {
            res = k1-s;
        }
    else {
            res=k2-k1;       
        }
    return res; 
}
double  OptionPricing::pay_off_call(double s, double k){
//    @param s: current stock price
//    @param k: the strike price of call option 
//    @return: pay off of call option  
    
    return max(0.0,s-k);
}

double  OptionPricing::pay_off_put(double s, double k){
//    @param s: current stock price
//    @param k: the strike price of put option
//    @param k2: in straddle option, the strike price of put option
//    @return: pay off of put option  
    
    return max(0.0,k-s);
}

double OptionPricing::straddle_option_european_binomial(const double &s, const double &r, const double &u_y, const double &d_y, const double &t, const int &steps, 
            double (OptionPricing::*pay_off_straddle)(double,double,double),double k1, double k2){
//    
//    @param s: the current stock price
//    @param r: annually interest rate
//    @param u_y: the increasing rate of stock price in one year
//    @param d_y: the decreasing rate of stock price in one year
//    @param t: option maturity time in years
//    @param steps: how many steps of the binomial tree
//    @param pay_off: pay off function of the option
//    @param k1: in straddle option, the strike price of call option
//    @param k2: in straddle option, the strike price of put option
//    @return: the European straddle option price
    double R = exp (r*t/steps); 
    double Rinv = 1.0/R; 
    double u = exp(log(u_y)/(steps/t));
    double d=exp(log(d_y)/(steps/t));
    double uu=u*u; 
    double p_up=(R-d)/(u-d);
    double p_down= 1.0-p_up;
    vector <double> prices (steps +1 );
    vector <double > value(steps +1);
    
    prices[0]=s*pow(d,steps); 


    // initialize the last column
    
    for (int i =1 ; i<=steps ;i++){
        prices[i] = uu* prices[i-1];
    }
    for (int i = 0;i<steps ; i++){
        value[i]=this->pay_off_straddle(prices[i],k1, k2);
        
    }
    
    
    double pay_off_temp;
    for (int step = steps -1 ; step >=0 ; step--){
        for(int i=0;i<=step;i++){
            value[i]=(p_up*value[i+1]+p_down*value[i])*Rinv;
        }
    }
    
    return value[0];      
}

double OptionPricing::straddle_option_american_binomial(const double &s, const double &r, const double &u_y, const double &d_y, const double &t, const int &steps, 
            double (OptionPricing::*pay_off_straddle)(double,double,double),double k1, double k2){
    //    
//    @param s: the current stock price
//    @param r: annually interest rate
//    @param u_y: the increasing rate of stock price in one year
//    @param d_y: the decreasing rate of stock price in one year
//    @param t: option maturity time in years
//    @param steps: how many steps of the binomial tree
//    @param pay_off: pay off function of the option
//    @param k1: in straddle option, the strike price of call option
//    @param k2: in straddle option, the strike price of put option
//    @return: the American straddle option price
    
    double R = exp ( r*t/steps); 
    double Rinv = 1.0/R; 
    double u = exp(log(u_y)/(steps/t));
    double d=exp(log(d_y)/(steps/t));
    double uu=u*u; 
    double p_up=(R-d)/(u-d);
    double p_down= 1.0-p_up;
    vector <double> prices (steps +1 );
    vector <double > value(steps +1);
    
    prices[0]=s*pow(d,steps); 


    // initialize the last column
    
    for (int i =1 ; i<=steps ;i++){
        prices[i] = uu* prices[i-1];
    }
    for (int i = 0;i<steps ; i++){
        value[i]=this->pay_off_straddle(prices[i],k1, k2);
    }
    
    
    double pay_off_temp;
    for (int step = steps -1 ; step >=0 ; step--){
        for(int i=0;i<=step;i++){
            value[i]=(p_up*value[i+1]+p_down*value[i])*Rinv;
            prices[i]=d*prices[i+1];
            pay_off_temp=this->pay_off_straddle(prices[i],k1,k2);
            value[i]=max(value[i],pay_off_temp);
        }
    }
    
    return value[0];      
}