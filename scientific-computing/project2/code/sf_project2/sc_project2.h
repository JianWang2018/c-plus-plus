/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   project2.h
 * Author: jianwang
 *
 * Created on November 14, 2017, 4:29 PM
 */

#ifndef PROJECT2_H
#define PROJECT2_H
#include<string>
using namespace std;
class ScProject2{
public:
    int count_words(string file_name);
    int delete_comments(string infile_name,string outfile_name);
    double matrix_multiply(int m , int n , string file_name);
    int write_matrix(int n, int m, string file_name);
};


#endif /* PROJECT2_H */

