#include<stdio.h>
#include <malloc.h>
#include<math.h>
# include"fcm.h"
# include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

double fcm::newton(int n, int N, double alpha,double (*func)(double ,double ))
{
    // define a write file variable
    vector <double> xx(N+1), Ny(N+1),yy(N+1),newNy(N+1);
    string file_name;
    ofstream fout;
    file_name="xx"+to_string(N)+".txt";
    fout.open (file_name);
    // write the x to the file in the first line
    // define 1000 true points in [-1,1]
    fout.precision(15);


    for (int k=0;k<=N;k++)
    {
        xx[k]=-1.0+2.0*k/N;
    }

    for ( double item: xx)
    {
        fout<<item<<endl;
    }
    fout.close();
    // call function1 to compute true values on true points
    for ( int k = 0; k<= N; k++)
    {
        yy[k]=func(alpha,xx[k]);
    }

    // write true value into a file
    file_name="yy"+to_string(N)+".txt";
    fout.open(file_name);
    for ( double item: yy)
    {
        fout<<item<<endl;
    }

    fout.close();

    vector <double> x(n+1),d(n+1),newd(n+1);
    for (int i =0;i<=n;i++)
    {// define n+1 mesh points
        x[i]=-1.0+2.0*i/n;
        // call func to compute true values on mesh points
        d[i]=func(alpha,x[i]);
        //make a pertubation
        newd[i]=d[i]+1.0e-7;
    }

    // compute the coefficients of Newton interpolating polynomial
    for(int i =1 ; i<=n;i++)
    {

        for(int j =n ; j>=i ;j--)
        {
            d[j]=(d[j]-d[j-1])/(x[j]-x[j-i]);
        }

    }
    // fout the d
    file_name="d"+to_string (N)+".txt";
    fout.open(file_name);
    for (int i = 0 ; i<= n ; i++)
    {
        fout<<d[i]<<endl;
    }

    fout.close();

    // compute interpolating values on the true points
    for (int k =0; k<=N;k++)
    {
        Ny[k]=d[n];
        for (int i=n-1;i>=0;i--)
        {
            Ny[k]=d[i]+(xx[k]-x[i])*Ny[k];
        }
    }
    // write interpolating values on true points
    file_name="Ny"+to_string(N)+".txt";
    fout.open(file_name);
    for(int k = 0; k<=N;k++)
    {
        fout<<Ny[k]<<endl;
    }
    fout.close();
// compute the coefficients of Newton interpolating polynomial
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= i; j--)
		{
			newd[j] = (newd[j] - newd[j - 1]) / (x[j] - x[j - i]);
		}
	}
// fout the newd
    file_name="newd"+to_string(N)+".txt";
    fout.open(file_name);
	for (int i = 0; i <= n; i++)
	{
		fout<<newd[i]<<endl;
	}
	fout.close();

	//compute interpolating values on true points
	for (int k = 0; k <= N; k++)
	{
		newNy[k] = newd[n];

		for (int i = n - 1; i >= 0; i--)
		{
			newNy[k] = newd[i] + (xx[k] - x[i])*newNy[k];
		}
	}
	// fout the interpolating values on true points
	file_name="newNy"+to_string(N)+".txt";
	fout.open(file_name);
	for(int k =0; k<=N;k++)
    {
        fout << newNy[k]<<endl;
    }
    fout.close();

	vector<double>p(N+1);
	for ( int i = 0; i<=N;i++)
    {
        p[i]=fabs(newNy[i]-Ny[i]);
    }
    double pmax;
    cout.precision(15);
    pmax=*max_element(p.begin(),p.end());
    cout<<"pmax is: "<<pmax<<endl;;
    double condition = 0.0;
    condition =pmax/(1.0e-7);
    cout<<"condition is: "<< condition<<endl;;

    // compute the error
    vector <double> error(N+1);
    double err=0.0;
    for (int i =0;i<=N;i++)
    {
        error[i]=fabs(yy[i]-Ny[i]);
        err=max(err,error[i]);
    }
    cout<<"the error is: "<<err<<endl;

    return 0.0;
}

double fcm::combination(int n, int k)
{
    int i= 0;
    double res =1.0;
    double min_value=0.0;

    if(k==1 || k==n)
    {
        res=1.0;
    }
    else
    {
        if (k<=n-k)
        {
            min_value=k;
        }
        else
        {
            min_value=n-k;
        }
        for(i =0;i<min_value;i++)
        {
            res=res*(n-i)/(i+1);
        }
    }
    return res;
}

float fcm::single_combination(int n, int k)
{
        int i= 0;
    float res =1.0;
    float min_value=0.0;

    if(k==1 || k==n)
    {
        res=1.0;
    }
    else
    {
        if (k<=n-k)
        {
            min_value=k;
        }
        else
        {
            min_value=n-k;
        }
        for(i =0;i<min_value;i++)
        {
            res=res*(n-i)/(i+1);
        }
    }
    return res;

}
double fcm::beinstein(int n, int N, double alpha,double (*func)(double ,double ))
{
    int k, i;
    vector <double> xx (N+1);
    // initialized the xx from the interval [0,1]
    for(i =0;i<=N;i++)
    {
        xx[i]=i*1.0/N;

    }

    // transform the data from [0,1] to [-1,1] use 2*x-1
    vector <double> new_xx(N+1);
    for (i =0;i<=N;i++)
    {
        new_xx[i]=2.0*xx[i]-1;
    }
    // write the point to file
    string file_name;
    ofstream fout;
    fout.precision(15);
    file_name = "new_xx_bs"+to_string(n)+".txt";
    fout.open(file_name);
    for(i = 0;i<=N;i++)
    {
        fout<<new_xx[i]<<endl;
    }
    fout.close();

    // compute the true values of the function based on new_xx
    vector<double> yy(N+1);
    for (i = 0;i<=N;i++)
    {
        yy[i]= func(alpha,new_xx[i]);
    }

    // write the true values into file
    fout.precision(15);
    file_name = "yy_bs"+to_string(n)+".txt";
    fout.open(file_name);
    for (i= 0; i<=N;i++)
    {
        fout<<yy[i]<<endl;
    }
    fout.close();

    vector<double> By(N+1);
    vector <double> x(n+1);
    vector <double> xnew(n+1);
    vector <double> y(n+1);
    vector <double> c(n+1);

    // main algorithm of berinstein

    for (i = 0; i <= N; i++)
	{
		By[i] = 0;
		for (k = 0; k <= n; k++)
		{
			x[k] = 1.0* k / n;
			xnew[k] = 2.0 * x[k] - 1;
			y[k] = func(alpha, xnew[k]);// call function1
			c[k] = combination(n, k);//call function combinatorial
			By[i] = By[i] + y[k] * c[k] * pow(xx[i], k)*pow((1 - xx[i]), (n - k));
		}
	}
	// write the interpolating values at true points into file
    fout.precision(15);
    file_name = "By_bs"+to_string(n)+".txt";
    fout.open(file_name);
    for (i=0;i<=N;i++)
    {
        fout<<By[i]<<endl;

    }
    fout.close();


    // next compute the result for pertubation, adding 1.0e-7 to the d[i]

    vector<double> new_By(N+1);
    vector <double> new_y(N+1);

    for (i = 0; i <= N; i++)
	{
		new_By[i] = 0;
		for (k = 0; k <= n; k++)
		{
			new_y[k] = y[k]+1.0e-7;
			c[k] = combination(n, k);//call function combinatorial
			new_By[i] = new_By[i] + new_y[k] * c[k] * pow(xx[i], k)*pow((1 - xx[i]), (n - k));
		}
	}

	// write the new value with pertubation of the true points into the file
    fout.precision(15);
    file_name = "newBy_bs"+to_string(n)+".txt";
    for(i =0; i<=N;i++)
    {
        fout<<new_By[i]<<endl;
    }
    fout.close();

    vector<double>p(N+1);
	for ( int i = 0; i<=N;i++)
    {
        p[i]=fabs(new_By[i]-By[i]);
    }

    double pmax;
    // retain 15 precision of result
    cout.precision(15);

    pmax=*max_element(p.begin(),p.end());

    cout<<"pmax is: "<<pmax<<endl;;

    double condition = 0.0;

    condition =pmax/(1.0e-7);
    cout<<"condition is: "<< condition<<endl;;

    // compute the error
    vector <double> error(N+1);
    double err=0.0;
    for (int i =0;i<=N;i++)
    {
        error[i]=fabs(yy[i]-By[i]);
        err=max(err,error[i]);
    }
    cout<<"the error is: "<<err<<endl;

    return 0.0;
}

double fcm::piecewise(int n , int N, double alpha,double (*func)(double,double))
{
    vector<double> x(n+1), y(n+1),new_y(n+1),xx(N+1),yy(N+1),PLy(N+1);

    for ( int i = 0; i<=n;i++)
    {   //initialized the mesh points
        x[i]=-1+2.0*i/n;
        //initilized y
        y[i]=func(alpha,x[i]);
        //compute the new y with permutation 1.0e-7;
        new_y[i]=y[i]+1.0e-7;
    }

        // compute the true points on interval [-1,1]
        for (int i =0;i<=N;i++)
        {
            xx[i]=-1.0+2.0*i/N;
        }
        ofstream fout;
        fout.precision(15);
        string file_name="xx_pl"+to_string(n)+".txt";
        fout.open(file_name);
        for(int i = 0; i <= N ; i++){
            fout<<xx[i]<<endl;
        }
        fout.close();



        //compute the true points of function
        for( int i = 0;i<=N;i++){
            yy[i]= func(alpha,xx[i]);
        }

        //write the true values of y into file
        fout.precision(15);
        file_name="yy_pl"+to_string(n)+".txt";
        fout.open(file_name);
        for(int i = 0; i <= N ; i++){
            fout<<yy[i]<<endl;
        }
        fout.close();

        // compute piecewise linear interpolating values
        // define the number of points in each pieces
        int M=N/n;

        for (int i = 0; i < n; i++)
		{
			for (int j = i*M; j <= (i + 1)*M; j++)
			{
			    PLy[j] = y[i] * (xx[j] - x[i + 1]) / (x[i] - x[i + 1]) + y[i + 1] * (xx[j] - x[i]) / (x[i + 1] - x[i]);
			}
		}
		// write the interpolating values to the file
        fout.precision(15);
        file_name="PLy"+to_string(n)+".txt";
        fout.open(file_name);
		 for(int i = 0; i<=N;i++){
            fout<<PLy[i]<<endl;
		 }
		 fout.close();
		 // now compute the result of pertubations, the pertubations value is chosen to be 1.0e-7
		 vector <double> new_PLy(N+1);
        // compute the piecewise linear interpolating values

        for (int i = 0; i < n; i++)
		{
			for (int j = i*M; j <= (i + 1)*M; j++)
			{
			    new_PLy[j] = new_y[i] * (xx[j] - x[i + 1]) / (x[i] - x[i + 1]) + new_y[i + 1] * (xx[j] - x[i]) / (x[i + 1] - x[i]);
			}
		}
//
//		// write the result to the file
		  fout.precision(15);
        file_name="newPLy"+to_string(n)+".txt";
        fout.open(file_name);
        for(int i = 0; i <= N ; i++){
            fout<<new_PLy[i]<<endl;
        }
        fout.close();

        // compute the condition numbers
        vector<double>p(N+1);
        for ( int i = 0; i<=N;i++)
        {
            p[i]=fabs(new_PLy[i]-PLy[i]);
        }

        double pmax;
        // retain 15 precision of result
        cout.precision(15);

        pmax=*max_element(p.begin(),p.end());

        cout<<"pmax is: "<<pmax<<endl;;

        double condition = 0.0;

        condition =pmax/(1.0e-7);
        cout<<"condition is: "<< condition<<endl;;

        // compute the error
        vector <double> error(N+1);
        double err=0.0;
        for (int i =0;i<=N;i++)
        {
            error[i]=fabs(yy[i]-PLy[i]);
            err=max(err,error[i]);
        }
        cout<<"the error is: "<<err<<endl;

        return 0.0;


}


// next is the single precision version of methods
float fcm::single_newton(int n, int N, float alpha,float (*func)(float ,float ))
{
    // define a write file variable
    vector <float> xx(N+1), Ny(N+1),yy(N+1),newNy(N+1);
    string file_name;
    ofstream fout;
    file_name="xx"+to_string(N)+".txt";
    fout.open (file_name);
    // write the x to the file in the first line
    // define 1000 true points in [-1,1]
    fout.precision(15);


    for (int k=0;k<=N;k++)
    {
        xx[k]=-1.0+2.0*k/N;
    }

    for ( float item: xx)
    {
        fout<<item<<endl;
    }
    fout.close();
    // call function1 to compute true values on true points
    for ( int k = 0; k<= N; k++)
    {
        yy[k]=func(alpha,xx[k]);
    }

    // write true value into a file
    file_name="yy"+to_string(N)+".txt";
    fout.open(file_name);
    for ( float item: yy)
    {
        fout<<item<<endl;
    }

    fout.close();

    vector <float> x(n+1),d(n+1),newd(n+1);
    for (int i =0;i<=n;i++)
    {// define n+1 mesh points
        x[i]=-1.0+2.0*i/n;
        // call func to compute true values on mesh points
        d[i]=func(alpha,x[i]);
        //make a pertubation
        newd[i]=d[i]+1.0e-7;
    }

    // compute the coefficients of Newton interpolating polynomial
    for(int i =1 ; i<=n;i++)
    {

        for(int j =n ; j>=i ;j--)
        {
            d[j]=(d[j]-d[j-1])/(x[j]-x[j-i]);
        }

    }
    // fout the d
    file_name="d"+to_string (N)+".txt";
    fout.open(file_name);
    for (int i = 0 ; i<= n ; i++)
    {
        fout<<d[i]<<endl;
    }

    fout.close();

    // compute interpolating values on the true points
    for (int k =0; k<=N;k++)
    {
        Ny[k]=d[n];
        for (int i=n-1;i>=0;i--)
        {
            Ny[k]=d[i]+(xx[k]-x[i])*Ny[k];
        }
    }
    // write interpolating values on true points
    file_name="Ny"+to_string(N)+".txt";
    fout.open(file_name);
    for(int k = 0; k<=N;k++)
    {
        fout<<Ny[k]<<endl;
    }
    fout.close();
// compute the coefficients of Newton interpolating polynomial
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= i; j--)
		{
			newd[j] = (newd[j] - newd[j - 1]) / (x[j] - x[j - i]);
		}
	}
// fout the newd
    file_name="newd"+to_string(N)+".txt";
    fout.open(file_name);
	for (int i = 0; i <= n; i++)
	{
		fout<<newd[i]<<endl;
	}
	fout.close();

	//compute interpolating values on true points
	for (int k = 0; k <= N; k++)
	{
		newNy[k] = newd[n];

		for (int i = n - 1; i >= 0; i--)
		{
			newNy[k] = newd[i] + (xx[k] - x[i])*newNy[k];
		}
	}
	// fout the interpolating values on true points
	file_name="newNy"+to_string(N)+".txt";
	fout.open(file_name);
	for(int k =0; k<=N;k++)
    {
        fout << newNy[k]<<endl;
    }
    fout.close();

	vector<float>p(N+1);
	for ( int i = 0; i<=N;i++)
    {
        p[i]=fabs(newNy[i]-Ny[i]);
    }
    float pmax;
    cout.precision(15);
    pmax=*max_element(p.begin(),p.end());
    cout<<"pmax is: "<<pmax<<endl;;
    float condition = 0.0;
    condition =pmax/(1.0e-7);
    cout<<"condition is: "<< condition<<endl;;

    // compute the error
    vector <float> error(N+1);
    float err=0.0;
    for (int i =0;i<=N;i++)
    {
        error[i]=fabs(yy[i]-Ny[i]);
        err=max(err,error[i]);
    }
    cout<<"the error is: "<<err<<endl;

    return 0.0;
}



float fcm::single_beinstein(int n, int N, float alpha,float (*func)(float ,float ))
{
    int k, i;
    vector <float> xx (N+1);
    // initialized the xx from the interval [0,1]
    for(i =0;i<=N;i++)
    {
        xx[i]=i*1.0/N;

    }

    // transform the data from [0,1] to [-1,1] use 2*x-1
    vector <float> new_xx(N+1);
    for (i =0;i<=N;i++)
    {
        new_xx[i]=2.0*xx[i]-1;
    }
    // write the point to file
    string file_name;
    ofstream fout;
    fout.precision(15);
    file_name = "new_xx_bs"+to_string(n)+".txt";
    fout.open(file_name);
    for(i = 0;i<=N;i++)
    {
        fout<<new_xx[i]<<endl;
    }
    fout.close();

    // compute the true values of the function based on new_xx
    vector<float> yy(N+1);
    for (i = 0;i<=N;i++)
    {
        yy[i]= func(alpha,new_xx[i]);
    }

    // write the true values into file
    fout.precision(15);
    file_name = "yy_bs"+to_string(n)+".txt";
    fout.open(file_name);
    for (i= 0; i<=N;i++)
    {
        fout<<yy[i]<<endl;
    }
    fout.close();

    vector<float> By(N+1);
    vector <float> x(n+1);
    vector <float> xnew(n+1);
    vector <float> y(n+1);
    vector <float> c(n+1);

    // main algorithm of berinstein

    for (i = 0; i <= N; i++)
	{
		By[i] = 0;
		for (k = 0; k <= n; k++)
		{
			x[k] = 1.0* k / n;
			xnew[k] = 2.0 * x[k] - 1;
			y[k] = func(alpha, xnew[k]);// call function1
			c[k] = single_combination(n, k);//call function combinatorial
			By[i] = By[i] + y[k] * c[k] * pow(xx[i], k)*pow((1 - xx[i]), (n - k));
		}
	}
	// write the interpolating values at true points into file
    fout.precision(15);
    file_name = "By_bs"+to_string(n)+".txt";
    fout.open(file_name);
    for (i=0;i<=N;i++)
    {
        fout<<By[i]<<endl;

    }
    fout.close();


    // next compute the result for pertubation, adding 1.0e-7 to the d[i]

    vector<float> new_By(N+1);
    vector <float> new_y(N+1);

    for (i = 0; i <= N; i++)
	{
		new_By[i] = 0;
		for (k = 0; k <= n; k++)
		{
			new_y[k] = y[k]+1.0e-7;
			c[k] = single_combination(n, k);//call function combinatorial
			new_By[i] = new_By[i] + new_y[k] * c[k] * pow(xx[i], k)*pow((1 - xx[i]), (n - k));
		}
	}

	// write the new value with pertubation of the true points into the file
    fout.precision(15);
    file_name = "newBy_bs"+to_string(n)+".txt";
    for(i =0; i<=N;i++)
    {
        fout<<new_By[i]<<endl;
    }
    fout.close();

    vector<float>p(N+1);
	for ( int i = 0; i<=N;i++)
    {
        p[i]=fabs(new_By[i]-By[i]);
    }

    float pmax;
    // retain 15 precision of result
    cout.precision(15);

    pmax=*max_element(p.begin(),p.end());

    cout<<"pmax is: "<<pmax<<endl;;

    float condition = 0.0;

    condition =pmax/(1.0e-7);
    cout<<"condition is: "<< condition<<endl;;

    // compute the error
    vector <float> error(N+1);
    float err=0.0;
    for (int i =0;i<=N;i++)
    {
        error[i]=fabs(yy[i]-By[i]);
        err=max(err,error[i]);
    }
    cout<<"the error is: "<<err<<endl;

    return 0.0;
}

float fcm::single_piecewise(int n , int N, float alpha,float (*func)(float,float))
{
    vector<float> x(n+1), y(n+1),new_y(n+1),xx(N+1),yy(N+1),PLy(N+1);

    for ( int i = 0; i<=n;i++)
    {   //initialized the mesh points
        x[i]=-1+2.0*i/n;
        //initilized y
        y[i]=func(alpha,x[i]);
        //compute the new y with permutation 1.0e-7;
        new_y[i]=y[i]+1.0e-7;
    }

        // compute the true points on interval [-1,1]
        for (int i =0;i<=N;i++)
        {
            xx[i]=-1.0+2.0*i/N;
        }
        ofstream fout;
        fout.precision(15);
        string file_name="xx_pl"+to_string(n)+".txt";
        fout.open(file_name);
        for(int i = 0; i <= N ; i++){
            fout<<xx[i]<<endl;
        }
        fout.close();



        //compute the true points of function
        for( int i = 0;i<=N;i++){
            yy[i]= func(alpha,xx[i]);
        }

        //write the true values of y into file
        fout.precision(15);
        file_name="yy_pl"+to_string(n)+".txt";
        fout.open(file_name);
        for(int i = 0; i <= N ; i++){
            fout<<yy[i]<<endl;
        }
        fout.close();

        // compute piecewise linear interpolating values
        // define the number of points in each pieces
        int M=N/n;

        for (int i = 0; i < n; i++)
		{
			for (int j = i*M; j <= (i + 1)*M; j++)
			{
			    PLy[j] = y[i] * (xx[j] - x[i + 1]) / (x[i] - x[i + 1]) + y[i + 1] * (xx[j] - x[i]) / (x[i + 1] - x[i]);
			}
		}
		// write the interpolating values to the file
        fout.precision(15);
        file_name="PLy"+to_string(n)+".txt";
        fout.open(file_name);
		 for(int i = 0; i<=N;i++){
            fout<<PLy[i]<<endl;
		 }
		 fout.close();
		 // now compute the result of pertubations, the pertubations value is chosen to be 1.0e-7
		 vector <float> new_PLy(N+1);
        // compute the piecewise linear interpolating values

        for (int i = 0; i < n; i++)
		{
			for (int j = i*M; j <= (i + 1)*M; j++)
			{
			    new_PLy[j] = new_y[i] * (xx[j] - x[i + 1]) / (x[i] - x[i + 1]) + new_y[i + 1] * (xx[j] - x[i]) / (x[i + 1] - x[i]);
			}
		}
//
//		// write the result to the file
		  fout.precision(15);
        file_name="newPLy"+to_string(n)+".txt";
        fout.open(file_name);
        for(int i = 0; i <= N ; i++){
            fout<<new_PLy[i]<<endl;
        }
        fout.close();

        // compute the condition numbers
        vector<float>p(N+1);
        for ( int i = 0; i<=N;i++)
        {
            p[i]=fabs(new_PLy[i]-PLy[i]);
        }

        float pmax;
        // retain 15 precision of result
        cout.precision(15);

        pmax=*max_element(p.begin(),p.end());

        cout<<"pmax is: "<<pmax<<endl;;

        float condition = 0.0;

        condition =pmax/(1.0e-7);
        cout<<"condition is: "<< condition<<endl;;

        // compute the error
        vector <float> error(N+1);
        float err=0.0;
        for (int i =0;i<=N;i++)
        {
            error[i]=fabs(yy[i]-PLy[i]);
            err=max(err,error[i]);
        }
        cout<<"the error is: "<<err<<endl;

        return 0.0;


}
void  fcm:: newton1 (int N, vector <double > xx, vector <double > difCo,double alpha, double(*func)(double,double))
{
vector<double > yy(N+1);
for (int i=0;i<=N;i++)
	{
		yy[i]=func(alpha, xx[i]);
	}
	for(int j=0;j<=N;j++)
	{
		difCo[j] = yy[j];
	}

	for(int i=0;i<N;i++)
	{
		for(int j=N;j>i;j--)
		{
			// cal difference coefficient
			difCo[j]=(difCo[j]-difCo[j-1])/(xx[j]-xx[j-1-i]);
		}
	}

}

double fcm:: newton2 (double x ,vector<double> xx, int  N, vector <double>difCo){

double sum=1.0;
double newy = difCo[0];
for (int i=0;i<N;i++)
	{
		sum=sum*(x-xx[i]);
		newy=newy+sum*difCo[i+1];
	}
	return newy;

}

double  fcm::piecewise2( double x, int s, int N, vector <double> xx, double alpha, double(*func )(double,double))
{
int locate = x/s;
int n=N/s;
if(locate<=n){
int i=locate;
		vector<double> partxx(s+1);
		vector<double> diffCo(s+1);
		for (int j=0;j<=s;j++)
		{
			partxx[j]=xx[i*s+j];
		}
		newton1(s, partxx, diffCo, alpha, func);
		double y = newton2(x, partxx, s, diffCo);
		return y;

}
return 0.0;
}

