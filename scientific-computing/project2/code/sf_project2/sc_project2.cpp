/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<iostream>
#include<string>
#include<cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include"sc_project2.h"
#include<fstream>
using namespace std;

int  ScProject2::count_words(string file_name){
    /* @target: count the word in the input source cpp file
     * @param file_name: the input file that we need to count the words
     * @return the number of words in the file
     */
    ifstream fin;
    char c;
    int count =0;
    fin.open(file_name.c_str());
    if (!fin.is_open()){
        cout<< " The file can not open";
        return 0;
    }
    int flag=0;
    while (!fin.eof()){
        c=fin.get();
        // note : we do not count continuous space and lines 
        if(isalnum(c)){
            flag=1;
        }
        // note : we can not use "" instead of '', "" is string and '' 
        // is character
        if((c==' ' || c=='\n') && flag==1){
            count++;
            flag=0;
        }
   
    }
    
    return count;
}

int  ScProject2::delete_comments(string infile_name,string outfile_name ){
    /* @target:delete all the comments in a cpp source file
     * @param infile_name: the input source file
     * @param outfule_name: the output file name without comments
     * @return:0    
     */
    ifstream fin;
    ofstream fout;
    char c;
    int count =0;
    // note: should change string to c_str(),otherwise can not open the file
    fin.open(infile_name.c_str());
    fout.open(outfile_name.c_str());
        
    if (!fin.is_open()){
        cout<< " The file can not read";
        return 0;
    }
    if(!fout.is_open()){
        cout<<"The file can not write";
        return 0;
           
    }
    c=fin.get();
    while (!fin.eof()){
        // note: two kinds of comment, one is // and another is /*...*/
        if(c=='/'){
            c=fin.get();
            if(c=='/'){
                while (c!='\n') c=fin.get();
            }
            else if(c=='*' || c=='\n'){
                while(c!='\n') c=fin.get();
            }
            
        }
        fout<<c;
        c=fin.get();
    }
    fin.close();
    fout.close();
    return 0;
}

double  ScProject2::matrix_multiply(int m, int n,string file_name){
    /* @target : read matrix and calculate the mean of the multiply of two matrix
     * @@param m: number of rows
     * @param n:number of columns
     * @param file_name: the txt file contains two matrix
     * @return: mean of the multiplication
     */
    ifstream fin;
    double a[m][n];
    double b[m][n];
    
    fin.open(file_name.c_str());
    if(!fin.is_open()){
        cout<< "The file can not be readed";
        return 0; 
    }
    // read the matrix into a and b
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin>>a[i][j];

        }             
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin>>b[i][j];

        }             
    }
    // multiply A to B 
    double c[m][n];
    for (int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			c[i][j] = 0.0;
			for (int k=0; k<n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
    // cout matrix c
//    for (int i=0; i<m; i++)
//	{
//		for(int j=0; j<n; j++)
//		{
//			cout<<c[i][j]<<" ";
//                }
//    }
    //compute the average of the matrix
    double sum = 0.0;
    double mean ;
	for (int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			sum = sum + c[i][j];
		}
	}
	mean = sum/(n*m);
    fin.close();
    return mean;
}

int  ScProject2::write_matrix(int n, int m, string file_name){
    /*
     * @tatget: write the matrix into a txt file
     * @param: number of rows 
     * @param: number of columns
     * @file_name: the file name that we write the matrix into
     * return: 0 
     */
    int i ;
    int j ;
    double A[n][m];
    double B[n][m];
    ofstream fout;
    // need to change from string to char[] with c_str()
    fout.open(file_name.c_str());
    if (!fout.is_open())
    {
        cout<<" The file can not write";
        return 0;
    }

    // initialize matrices A and B;

    for (i = 0; i < m; i++)
    {
            for (j = 0; j < n; j++)
            {
                    A[i][j] = i+j+1.0;
                    B[i][j] = 1/(i+j+1.0);
            }
    }

    // write A into the file;

        for (i = 0; i < m; i++)
    {
            for (j = 0; j < n; j++)
            {
                fout<<A[i][j]<<' ';
            }
            fout<<endl;
    }

	// write B into the file;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                fout<<B[i][j]<<' ';
            }
            fout<<endl;
        }

    fout.close();
    
    return 0;
}