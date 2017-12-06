/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jianwang
 *
 * Created on November 14, 2017, 4:29 PM
 */

#include <cstdlib>
#include<iostream>
#include<string>
#include<cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include"sc_project2.h"
#include<fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    string infile_name ="codefile.txt";
    string outfile_name="nocomment.txt";
    string matrix_file_name="matrix.txt";
    ScProject2 res;
    int count; 
    //1. calculate the word counts;
    count=res.count_words(infile_name);
    // 2. delete all the comments
    res.delete_comments(infile_name,outfile_name);
    // 3.write the matrix into file
    res.write_matrix(10,10,matrix_file_name);
    //4. calculate the mean of the multiplication matrix
    double mat_mean=0.0;
    mat_mean=res.matrix_multiply(10,10, matrix_file_name);
    cout.precision(10);
    cout<<mat_mean;
    return 0;
}

