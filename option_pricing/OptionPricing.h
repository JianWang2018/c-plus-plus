/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OptionPricing.h
 * Author: jianwang
 *
 * Created on December 6, 2017, 1:38 AM
 */

#ifndef OPTIONPRICING_H
#define OPTIONPRICING_H

class OptionPricing{
    
    public:
        double  pay_off_straddle(double s, double k1, double k2);
        double  pay_off_call(double s , double k);
        double  pay_off_put(double s ,double k);
 
        double straddle_option_european_binomial(const double &s, const double & r,const double &u,const double &d,const double &t,const int &steps,
            double (OptionPricing::*pay_off_straddle)(double,double,double)
        ,double k1,double k2);        
        double straddle_option_american_binomial(const double &s, const double & r,const double &u,const double &d,const double &t,const int &steps,
            double (OptionPricing::*pay_off_straddle)(double,double,double)
        ,double k1,double k2);
};


#endif /* OPTIONPRICING_H */

