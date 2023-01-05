#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double f(double y){
    const double pi=3.14159;
    return((-(pi*pi)/4)*(y+1));
}

double HK4(double x_i, double x_f, double p, double y)
{
    double k1,k2,k3,k4,m1,m2,m3,m4,y_n1,p_n1 ;
    double h = ( x_f - x_i )/100;  // SIZE STEP. 
    while (x_i<x_f)
    {
        k1 = h*(  p );
        m1 = h*f( y );

        k2 = h*(  p + 0.5*m1 );
        m2 = h*f( y + 0.5*k1 );

        k3 = h*(  p + 0.5*m2 );
        m3 = h*f( y + 0.5*k2 );

        k4 = h*(  p + m3 );   
        m4 = h*f( y + k3 );   
                    
        y_n1 = y + ( k1 + 2*k2 + 2*k3 + k4 )/6;
        p_n1 = p + ( m1 + 2*m2 + 2*m3 + m4 )/6;
                
        x_i = x_i + h;
        y   = y_n1;
        p   = p_n1;
    }
    return y_n1;    
}

int main()
{
    // DECLARANDO AS VARIAVEIS           //
    double y, p,x, x_f = 1, x_i = 0, y_i = 0, y_real = 1, h;
    // CONDIÇÕES INICIAIS                //
    h = 10;                              // SIZE STEP. 
    p = 0 ;                              // CHUTE.
    y = y_i;
    // FINDING THE INITIAL CONDITIONS.   // 
    double parametro =y_real- y,parametro_1;
    while(abs(parametro)>0.00000001)
    {
        //cout<< " p = "<< p <<" y = "<< y <<"\n";
        parametro   = HK4( x_i, x_f, p, y_i) - y_real;
        parametro_1 = HK4( x_i, x_f, p + h, y_i) - y_real;

        if(parametro*parametro_1<0 )
        {
            h = h*0.5;
            //cout<<" new h = "<< h<<"\n";
        }
        else
        {
            p = p + h;
        }
    } 
    cout<<x_i<<"-"<<x_f<<"-"<<p<<"\n";

    // CRIANDA OS DADOS PARA PLOT        //
    double k1,k2,k3,k4,m1,m2,m3,m4,y_n1,p_n1 ; 
    fstream FILE;                        // DECLARING VARIABLE
    FILE.open("Data/data.csv",ios::out); // OPEN THE FILE 
    FILE<<"x,y"<<"\n";                   // SAVE THE INICITAL CONDITIONS
    h = ( x_f - x_i )/100;                // SIZE STEP
    y = y_i;                             
    while (x_i<x_f)
    {
        k1 = h*(  p );
        m1 = h*f( y );

        k2 = h*(  p + 0.5*m1 );
        m2 = h*f( y + 0.5*k1 );

        k3 = h*(  p + 0.5*m2 );
        m3 = h*f( y + 0.5*k2 );

        k4 = h*(  p + m3 );   
        m4 = h*f( y + k3 );   
                    
        y_n1 = y + ( k1 + 2*k2 + 2*k3 + k4 )/6;
        p_n1 = p + ( m1 + 2*m2 + 2*m3 + m4 )/6;

        FILE<< x_i <<","<<y_n1 <<"\n";       
        
        x_i = x_i + h;
        y   = y_n1;
        p   = p_n1;
    }
    FILE.close();

}