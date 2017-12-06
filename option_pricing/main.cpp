/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jianwang
 *
 * Created on December 6, 2017, 1:37 AM
 */

#include <cstdlib>
#include<iostream>
#include<vector>
#include"OptionPricing.h"
using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    // s is the current price, r is the annual interest rate
    double s=23.0, r=0.05,u=1.1,d=0.9,t=2.0,k1=23.4,k2=24.4;
    int steps = 100;
    OptionPricing res;
    // note we can use &OptionPricing::pay_off_straddle to use a member function as an augment 
    cout<<"The America straddle option price is:"<<res.straddle_option_american_binomial(s,r,u,d,t,steps,&OptionPricing::pay_off_straddle,k1,k2)<<endl ; 
    cout<<" The European straddle option price is:"<<res.straddle_option_european_binomial(s,r,u,d,t,steps,&OptionPricing::pay_off_straddle,k1,k2);
    return 0;
}

